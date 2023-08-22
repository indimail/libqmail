/*
 * $Id: tls.c,v 1.9 2023-08-22 20:00:23+05:30 Cprogrammer Exp mbhangui $
 *
 * ssl_timeoutio functions froms from Frederik Vermeulen's
 * tls patch for qmail
 * https://inoa.net/qmail-tls/netqmail-1.06-tls-20200107.patch
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#ifdef HAVE_SSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <case.h>
#endif
#include <str.h>
#include <ndelay.h>
#include <taia.h>
#include <strerr.h>
#include <env.h>
#include <getEnvConfig.h>
#include <error.h>
#include <stralloc.h>
#include <alloc.h>
#include <scan.h>
#include <timeoutread.h>
#include <timeoutwrite.h>
#include <allwrite.h>
#include "iopause.h"
#include "tls.h"

#ifndef	lint
static char     sccsid[] = "$Id: tls.c,v 1.9 2023-08-22 20:00:23+05:30 Cprogrammer Exp mbhangui $";
#endif

#ifdef HAVE_SSL
static enum tlsmode usessl = none;
static char    *sslerr_str;
static SSL     *ssl_t;
static int      efd = -1, ssl_rfd = -1, ssl_wfd = -1; /*- SSL_get_fd() are broken */
static char     do_shutdown;
static char    *certdir;
struct strerr   strerr_tls;

void
set_essential_fd(int fd)
{
	efd = fd;
	return;
}

void
set_ssl_fd(SSL *myssl, int rfd, int wfd)
{
	if (myssl) {
		ssl_rfd = rfd;
		SSL_set_rfd(myssl, rfd);
		ssl_wfd = wfd;
		SSL_set_wfd(myssl, wfd);
	}
	return;
}

void
ssl_free()
{
	if (!ssl_t)
		return;
	if (do_shutdown) {
		while (SSL_shutdown(ssl_t) == 0)
			usleep(100);
		do_shutdown = 0;
	}
	SSL_free(ssl_t);
	if (usessl != none)
		usessl = none;
	efd = ssl_rfd = ssl_wfd = -1;
	ssl_t = (SSL *) NULL;
}

void
set_certdir(char *s)
{
	certdir = s;
	return;
}

#if OPENSSL_VERSION_NUMBER < 0x30000000L
RSA            *
tmp_rsa_cb(SSL *ssl_p, int export, int keylen)
{
	stralloc        filename = { 0 };
	char           *pems[] = {"8192", "4096", "2048", "1024", "512", 0};
	char          **ptr;
	int             i, j;
	FILE           *in;
	RSA            *rsa;
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	BIGNUM         *bn;
	RSA            *key;
#endif

	if (!export)
		keylen = 512;
	if (!stralloc_copys(&filename, certdir) ||
			!stralloc_catb(&filename, "/rsa", 4))
		strerr_die1x(111, "out of memory");
	j = filename.len;
	for (ptr = pems; *ptr; ptr++) {
		scan_int(*ptr, &i);
		if (keylen != i)
			continue;
		if (!stralloc_cats(&filename, *ptr) ||
				!stralloc_catb(&filename, ".pem", 4) ||
				!stralloc_0(&filename))
			strerr_die1x(111, "out of memory");
		filename.len = j;
		if (!(in = fopen(filename.s, "r"))) {
			if (errno != error_noent)
				strerr_die1sys(111, "tmp_rsa_cb: error reading rsa private key: ");
			continue;
		}
		if (!(rsa = PEM_read_RSAPrivateKey(in, NULL, NULL, NULL)))
			strerr_die1sys(111, "error reading rsa private key: ");
		fclose(in);
		alloc_free(filename.s);
		return rsa;
	}
	alloc_free(filename.s);
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	if (!(bn = BN_new()))
		strerr_die1x(111, "out of memory");
	if (!BN_set_word(bn, 65537))
		strerr_die1sys(111, "error setting BIGNUM: ");
	if (!(key = RSA_new()))
		strerr_die1x(111, "out of memory");
	if (!RSA_generate_key_ex(key, keylen, bn, NULL))
		strerr_die1sys(111, "error generating RSA keys: ");
	BN_free(bn);
	return (key);
#else
	return RSA_generate_key(keylen, RSA_F4, NULL, NULL);
#endif
}

DH             *
tmp_dh_cb(SSL *ssl_p, int export, int keylen)
{
	stralloc        filename = { 0 };
	char           *pems[] = {"8192", "4096", "2048", "1024", "512", 0};
	char          **ptr;
	int             i, j;
	FILE           *in;
	DH             *dh;
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	DH             *client_key;
#endif

	if (!export)
		keylen = 1024;
	if (!stralloc_copys(&filename, certdir) ||
			!stralloc_catb(&filename, "/dh", 3))
		strerr_die1x(111, "out of memory");
	j = filename.len;
	for (ptr = pems; *ptr; ptr++) {
		scan_int(*ptr, &i);
		if (keylen != i)
			continue;
		if (!stralloc_cats(&filename, *ptr) ||
				!stralloc_catb(&filename, ".pem", 4) ||
				!stralloc_0(&filename))
			strerr_die1x(111, "out of memory");
		filename.len = j;
		if (!(in = fopen(filename.s, "r"))) {
			if (errno != error_noent)
				strerr_die1sys(111, "error reading dh parameters: ");
			continue;
		}
		if (!(dh = PEM_read_DHparams(in, NULL, NULL, NULL)))
			strerr_die1sys(111, "error reading dh parameters: ");
		fclose(in);
		alloc_free(filename.s);
		return dh;
	}
	alloc_free(filename.s);
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	if (!(client_key = DH_new()))
		strerr_die1x(111, "out of memory");
	if (!DH_generate_parameters_ex(client_key, keylen, DH_GENERATOR_2, NULL))
		strerr_die1sys(111, "error generating DH parameters: ");
	return (client_key);
#else
	return DH_generate_parameters(keylen, DH_GENERATOR_2, NULL, NULL);
#endif
}
#else /*- #if OPENSSL_VERSION_NUMBER < 0x30000000L */
EVP_PKEY       *
get_rsakey(int export, int keylen, char *_certdir)
{
	stralloc        filename = { 0 };
	char           *pems[] = {"8192", "4096", "2048", "1024", "512", 0};
	char          **ptr;
	BIO            *in;
	int             i, j;
	EVP_PKEY       *rsa_key;

	if (!export) /*- bullshit */
		keylen = 1024;
	if (!stralloc_copys(&filename, _certdir) ||
			!stralloc_catb(&filename, "/rsa", 4))
		strerr_die1x(111, "out of memory");
	j = filename.len;
	for (ptr = pems; *ptr; ptr++) {
		scan_int(*ptr, &i);
		if (keylen != i)
			continue;
		if (!stralloc_cats(&filename, *ptr) ||
				!stralloc_catb(&filename, ".pem", 4) ||
				!stralloc_0(&filename))
			strerr_die1x(111, "out of memory");
		filename.len = j;
		if (access(filename.s, F_OK)) {
			if (errno != error_noent)
				strerr_die3sys(111, "error reading rsa parameters ", filename.s, ": ");
			continue;
		}
		if ((in = BIO_new(BIO_s_file()))) {
			if (BIO_read_filename(in, filename.s) <= 0) {
				BIO_free(in);
				continue;
			}
			alloc_free(filename.s);
			if (!(rsa_key = PEM_read_bio_PrivateKey(in, NULL, 0, NULL))) {
				BIO_free(in);
				continue;
			}
			BIO_free(in);
			return rsa_key;
		} else
			strerr_die1x(111, "out of memory");
	}
	alloc_free(filename.s);
	return ((EVP_PKEY *) NULL);
}

EVP_PKEY       *
get_dhkey(int export, int keylen, char *_certdir)
{
	stralloc        filename = { 0 };
	char           *pems[] = {"8192", "4096", "2048", "1024", "512", 0};
	char          **ptr;
	int             i, j;
	BIO            *in;
	EVP_PKEY       *dh_key;

	if (!export) /*- bullshit */
		keylen = 1024;
	if (!stralloc_copys(&filename, _certdir) ||
			!stralloc_catb(&filename, "/dh", 3))
		strerr_die1x(111, "out of memory");
	j = filename.len;
	for (ptr = pems; *ptr; ptr++) {
		scan_int(*ptr, &i);
		if (keylen == i)
			continue;
		if (!stralloc_cats(&filename, *ptr) ||
				!stralloc_catb(&filename, ".pem", 4) ||
				!stralloc_0(&filename))
			strerr_die1x(111, "out of memory");
		filename.len = j;
		if (access(filename.s, F_OK)) {
			if (errno != error_noent)
				strerr_die3sys(111, "error reading dh parameters ", filename.s, ": ");
			continue;
		}
		if ((in = BIO_new(BIO_s_file()))) {
			if (BIO_read_filename(in, filename.s) <= 0) {
				BIO_free(in);
				continue;
			}
			alloc_free(filename.s);
			if (!(dh_key = PEM_read_bio_Parameters_ex(in, NULL, NULL, NULL))) {
				BIO_free(in);
				continue;
			}
			BIO_free(in);
			return dh_key;
		} else
			strerr_die1x(111, "out of memory");
	}
	return ((EVP_PKEY *) NULL);
}
#endif /*- #if OPENSSL_VERSION_NUMBER < 0x30000000L */

void
set_rsa_dh(SSL_CTX *ctx)
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
	EVP_PKEY       *dh_pkey;
	int             bits;

	getEnvConfigInt(&bits, "SSL_BITS", 2048);
	/*-
	 * if we don't get pre-generated RSA/DH parameters
	 * we generate it using EVP_RAS_gen, SSL_CTX_set_dh_auto
	 * which will be slower
	 */
	if (!get_rsakey(0, bits, certdir))
		EVP_RSA_gen(bits);
	if (!(dh_pkey = get_dhkey(0, bits, certdir)))
		SSL_CTX_set_dh_auto(ctx, 1);
	else
		SSL_CTX_set0_tmp_dh_pkey(ctx, dh_pkey);
#else
	SSL_CTX_set_tmp_rsa_callback(ctx, tmp_rsa_cb);
	SSL_CTX_set_tmp_dh_callback(ctx, tmp_dh_cb);
#endif
}

/*
 * don't want to fail handshake if certificate can't be verified
 */
static int
verify_cb(int preverify_ok, X509_STORE_CTX *ctx)
{
	return 1;
}

const char     *
myssl_error()
{
	int             r = ERR_get_error();
	if (!r)
		return NULL;
	SSL_load_error_strings();
	return ERR_error_string(r, NULL);
}

const char     *
myssl_error_str()
{
	const char     *err = myssl_error();

	if (err)
		return err;
	if (!errno)
		return 0;
	return (errno == ETIMEDOUT) ? "timed out" : error_str(errno);
}

static int
check_cert(SSL *myssl, char *host)
{
	X509           *peer;
	char            peer_CN[256];

	if (SSL_get_verify_result(myssl) != X509_V_OK) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_get_verify_result: ", sslerr_str, 0);
		return (1);
	}
	/*
	 * Check the cert chain. The chain length
	 * is automatically checked by OpenSSL when
	 * we set the verify depth in the ctx
	 */

	/*- Check the common name */
	if (!(peer = SSL_get_peer_certificate(myssl))) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_get_peer_certificate: ", sslerr_str, 0);
		return (1);
	}
	X509_NAME_get_text_by_NID(X509_get_subject_name(peer), NID_commonName, peer_CN, sizeof(peer_CN) - 1);
	if (host && case_diffs(peer_CN, host)) {
		strerr_warn2("hostname doesn't match Common Name ", peer_CN, 0);
		return (1);
	}
	return (0);
}

/*
 * gets the highest supported verison
 */
int
get_tls_method(char *vstr)
{
	if (!vstr) {
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
		/*- (1,2 unused) 3=SSLv3, 4 = TLSv1, 5=TLSv1.1, 6=TLSv1.2, 7=TLSv1.3 */
		return 7;
#elif OPENSSL_VERSION_NUMBER >= 0x10100000L
		/*- (1 unused) 2 = SSLv23, 3=SSLv3, 4 = TLSv1, 5=TLSv1.1, 6=TLSv1.2 */
		return 6;
#else
		return 3;
#endif
	}
	return (sslvstr_to_method(vstr));
}

/*
 * convert ssl version string to libqmail numerical number
 * representing ssl/tls version (1, 2, 3, 4, ...)
 */
int
sslvstr_to_method(char *vstr)
{
	int             i = 0;
	char           *p;

	i = str_chr(vstr, ':');
	if (vstr[i]) {
		if (vstr[i + 1])
			p = vstr + i + 1;
		else {
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
			return 7;
#elif OPENSSL_VERSION_NUMBER >= 0x10100000L
			return 6;
#else
			return 3;
#endif
		}
	} else
		p = vstr;
#if OPENSSL_VERSION_NUMBER < 0x10100000L
	if (str_equal(p, "SSLv23"))
		return 2;
	else
	if (str_equal(p, "SSLv3"))
		return 3;
	else
#endif
	if (str_equal(p, "TLSv1"))
		return 4;
	else
	if (str_equal(p, "TLSv1_1"))
		return 5;
	else
	if (str_equal(p, "TLSv1_2"))
		return 6;
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
	else
	if (str_equal(p, "TLSv1_3"))
		return 7;
#endif
	else
		return -1;
}

/*
 * convert libqmail ssl numerical version
 * to SSL/TLS VERSION
 */
int
sslmethod_to_version(int method)
{
	switch (method)
	{
	case 2:
		return SSL2_VERSION;
	case 3:
		return SSL3_VERSION;
	case 4:
		return TLS1_VERSION;
	case 5:
		return TLS1_1_VERSION;
	case 6:
		return TLS1_2_VERSION;
		break;
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
	case 7:
		return TLS1_3_VERSION;
#endif
	}
	return 0;
}

static void
print_invalid_method(char *sslver)
{
	strerr_warn3("tls_method: Invalid TLS method configured [", sslver ? sslver : "[", "]", 0);
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
	strerr_warn1("tls_method: Supported methods: SSLv23, SSLv3, TLSv1, TLSv1_1, TLSv1_2, TLSv1_3", 0);
#elif OPENSSL_VERSION_NUMBER >= 0x10100000L
	strerr_warn1("tls_method: Supported methods: SSLv23, SSLv3, TLSv1, TLSv1_1, TLSv1_2", 0);
#else
	strerr_warn1("tls_method: Supported methods: SSLv23, SSLv3", 0);
#endif
	return;
}

SSL_CTX        *
set_tls_method(char *ssl_option, int *method, enum tlsmode tmode, int *method_fail)
{
	SSL_CTX        *ctx = (SSL_CTX *) NULL;
	int             i = 0, min_version = 0, max_version = 0, t;

#if OPENSSL_VERSION_NUMBER < 0x1010107f
	/*- (1 unused) 2 = SSLv23, 3=SSLv3, 4 = TLSv1, 5=TLSv1.1, 6=TLSv1.2 */
	*method = 4;
#else
	/*- (1,2 unused) 3=SSLv3, 4 = TLSv1, 5=TLSv1.1, 6=TLSv1.2, 7=TLSv1.3 */
	*method = 0; /*- method = 0 -> auto */
#endif
	if (ssl_option) {
		i = str_chr(ssl_option, ':');
		if (ssl_option[i]) {
			ssl_option[i] = '\0';
			if (i) { /* min number specified */
				if ((t = sslvstr_to_method(ssl_option)) == -1) {
					if (method_fail) {
						*method_fail = 1;
						errno = EPROTO;
						return ((SSL_CTX *) NULL);
					}
					ssl_option[i] = ':';
					print_invalid_method(ssl_option);
					errno = EPROTO;
					return ((SSL_CTX *) NULL);
				}
				min_version = sslmethod_to_version(t);
			}
			i++;
			if (ssl_option[i]) { /* max number specified */
				if ((t = sslvstr_to_method(ssl_option + i)) == -1) {
					if (method_fail) {
						*method_fail = 1;
						errno = EPROTO;
						return ((SSL_CTX *) NULL);
					}
					ssl_option[i - 1] = ':';
					print_invalid_method(ssl_option);
					errno = EPROTO;
					return ((SSL_CTX *) NULL);
				} else
					*method = t;
				max_version = sslmethod_to_version(t);
			}
		} else { /* version doesn't have min and max */
			if ((t = sslvstr_to_method(ssl_option)) == -1) {
				errno = EPROTO;
				if (method_fail) {
					*method_fail = 1;
					return ((SSL_CTX *) NULL);
				}
				print_invalid_method(ssl_option);
				return ((SSL_CTX *) NULL);
			} else
				*method = t;
			max_version = sslmethod_to_version(t);
		}
	} /*- if (ssl_option) */
	if (method_fail)
		*method_fail = *method;
	errno = 0;
	SSL_library_init();
	/*- a new SSL context with the bare minimum of options */
#if OPENSSL_VERSION_NUMBER < 0x10100000L
	if (*method == 2 && !(ctx = SSL_CTX_new(tmode == client ? SSLv23_client_method() : SSLv23_server_method()))) {
		sslerr_str = (char *) myssl_error_str();
		if (!method_fail)
			strerr_warn2("tls_method: unable to initialize SSLv23 ctx: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL);
	} else
	if (*method == 3 && !(ctx = SSL_CTX_new(tmode == client ? SSLv3_client_method() : SSLv3_server_method()))) {
		sslerr_str = (char *) myssl_error_str();
		if (!method_fail)
			strerr_warn2("tls_method: unable to initialize SSLv3 ctx: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL);
	} else
#if (defined(TLSV1_CLIENT_METHOD) && defined(TLSv1_SERVER_METHOD)) || defined(TLS1_VERSION)
	if (*method == 4 && !(ctx = SSL_CTX_new(tmode == client ? TLSv1_client_method() : TLSv1_server_method()))) {
		sslerr_str = (char *) myssl_error_str();
		if (!method_fail)
			strerr_warn2("tls_method: unable to initialize TLSv1 ctx: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL);
	} else
#else
	if (*method == 4) {
		errno = EPROTO;
		if (!method_fail)
			strerr_warn1("tls_method: TLSv1 method not available: ", &strerr_sys);
		return ((SSL_CTX *) NULL);
	} else
#endif
#if (defined(TLSV1_1_CLIENT_METHOD) && defined(TLSV1_1_SERVER_METHOD)) || defined(TLS1_1_VERSION)
	if (*method == 5 && !(ctx = SSL_CTX_new(tmode == client ? TLSv1_1_client_method() : TLSv1_1_server_method()))) {
		sslerr_str = (char *) myssl_error_str();
		if (!method_fail)
			strerr_warn2("tls_method: unable to initialize TLSv1_1 ctx: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL);
	} else
#else
	if (*method == 5) {
		errno = EPROTO;
		if (!method_fail)
			strerr_warn1("tls_method: TLSv1_1_server_method not available: ", &strerr_sys);
		return ((SSL_CTX *) NULL);
	} else
#endif
#if (defined(TLSV1_2_CLIENT_METHOD) && defined(TLSV1_2_SERVER_METHOD)) || defined(TLS1_2_VERSION)
	if (*method == 6 && !(ctx = SSL_CTX_new(tmode == client ? TLSv1_2_client_method() : TLSv1_2_server_method()))) {
		sslerr_str = (char *) myssl_error_str();
		if (!method_fail)
			strerr_warn2("tls_method: unable to initialize TLSv1_2 ctx: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL) ;
	} else
#else
	if (*method == 6) {
		errno = EPROTO;
		if (!method_fail)
			strerr_warn1("tls_method: TLSv1_2_server_method not available: ", &strerr_sys);
		return ((SSL_CTX *) NULL) ;
	}
#endif
#else /*- OPENSSL_VERSION_NUMBER >= 0x10100000L */
	switch (tmode)
	{
	case qremote:
	case client:
		ctx = SSL_CTX_new(TLS_client_method());
		break;
	case qsmtpd:
	case server:
		ctx = SSL_CTX_new(TLS_server_method());
		break;
	default:
		ctx = SSL_CTX_new(TLS_method());
		break;
	}
	/*-
	 * Currently supported versions are
	 * TLS1_2_VERSION, TLS1_3_VERSION for TLS
	 */
	if (*method && ctx) {
		if (min_version && !SSL_CTX_set_min_proto_version(ctx, min_version)) {
			sslerr_str = (char *) myssl_error_str();
			if (!method_fail)
				strerr_warn2("SSL_CTX_set_min_proto: ", sslerr_str, 0);
		}
		if (max_version && !SSL_CTX_set_max_proto_version(ctx, max_version)) {
			sslerr_str = (char *) myssl_error_str();
			if (!method_fail)
				strerr_warn2("SSL_CTX_set_max_proto: ", sslerr_str, 0);
		}
	}
#endif /*- OPENSSL_VERSION_NUMBER < 0x10100000L */
	if (!ctx && method_fail)
		*method_fail = 0;
	return ctx;
}

SSL_CTX        *
tls_init(char *tls_method, char *cert, char *cafile, char *crlfile,
		char *ciphers, enum tlsmode tmode)
{
	static SSL_CTX *ctx = (SSL_CTX *) NULL;
	int             method, r;
#if OPENSSL_VERSION_NUMBER >= 0x00907000L
	X509_STORE     *store;
	X509_LOOKUP    *lookup;
#endif

	if (ctx)
		return (ctx);
	if (!certdir && (tmode == server || tmode == qsmtpd)) {
		strerr_warn1("tls_init: certdir not set", 0);
		return ((SSL_CTX *) NULL);
	}

	ctx = set_tls_method(tls_method, &method, tmode, 0);
	if (!ctx) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_CTX_new: error initializing method: ", sslerr_str, 0);
		return ((SSL_CTX *) NULL);
	}
	/*- POODLE Vulnerability */
	SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
	/*-
	 *  When performing renegotiation as a server, always start a new session
	 *  (i.e., session resumption requests are only accepted in the initial
	 *  handshake). This option is not needed for clients
	 */
	if (tmode != client)
		SSL_CTX_set_options(ctx, SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION);

	/* never bother the application with retries if the transport is blocking */
	SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);

	/* relevant in renegotiation */
	if (tmode != client) {
		if (!SSL_CTX_set_session_id_context(ctx, (const unsigned char *) "tcpserver", 9)) {
			sslerr_str = (char *) myssl_error_str();
			strerr_warn2("tls_init: failed to set session_id context: ", sslerr_str, 0);
			SSL_CTX_free(ctx);
			return ((SSL_CTX *) NULL) ;
		}
	}
	SSL_CTX_set_session_cache_mode(ctx, SSL_SESS_CACHE_OFF);
#if 0
	SSL_CTX_set_session_cache_mode(ctx, SSL_SESS_CACHE_SERVER|SSL_SESS_CACHE_UPDATE_TIME);
	/*- SSL_CTX_set_timeout(ctx, dtimeout); -*/
#endif
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
	SSL_CTX_set1_groups_list(ctx, "P-256:P-384:P-521:X25519:X448:ffdhe2048:ffdhe3072:ffdhe4096:ffdhe6144:ffdhe8192");
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10002000L
	/* support ECDH */
	SSL_CTX_set_ecdh_auto(ctx, 1);
#endif
	if (tmode == server) {
		if (1 != SSL_CTX_load_verify_locations(ctx, cert, certdir)) {
			sslerr_str = (char *) myssl_error_str();
			strerr_warn4("unable to load CA certificate: ", cert, ": ", sslerr_str, 0);
			SSL_CTX_free(ctx);
			return ((SSL_CTX *) NULL);
		}
		if (cafile && 1 != SSL_CTX_load_verify_locations(ctx, cafile, certdir)) {
			sslerr_str = (char *) myssl_error_str();
			strerr_warn4("SSL_CTX_load_verify_locations: Unable to load CA certificate: ", cafile, ": ", sslerr_str, 0);
			SSL_CTX_free(ctx);
			return ((SSL_CTX *) NULL);
		}
#if OPENSSL_VERSION_NUMBER >= 0x00907000L
		/*- crl checking */
		if (crlfile) {
			store = SSL_CTX_get_cert_store(ctx);
			if ((lookup = X509_STORE_add_lookup(store, X509_LOOKUP_file())) &&
					X509_load_crl_file(lookup, crlfile, X509_FILETYPE_PEM) == 1)
				X509_STORE_set_flags(store, X509_V_FLAG_CRL_CHECK | X509_V_FLAG_CRL_CHECK_ALL);
		}
#endif
	}
	/*- set the callback here; SSL_set_verify didn't work before 0.9.6c */
	SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, verify_cb);
	/*-
	 * Set our cipher list
	 * The format of the string is described in openssl-ciphers(1)
	 *
	 * for method >= 7 (> TLSv1_3), default is
	 * default is TLS_AES_256_GCM_SHA384:TLS_CHACHA20_POLY1305_SHA256:TLS_AES_128_GCM_SHA256
	 */
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
	if (method && method < 7 && !ciphers)
		ciphers = "PROFILE=SYSTEM";
	r = ciphers ? (method && method < 7 ? SSL_CTX_set_cipher_list : SSL_CTX_set_ciphersuites) (ctx, ciphers) : 1;
#else
	if (!ciphers)
		ciphers = "PROFILE=SYSTEM";
	r = SSL_CTX_set_cipher_list(ctx, ciphers);
#endif
	if (!r) {
		sslerr_str = (char *) myssl_error_str();
#if OPENSSL_VERSION_NUMBER >= 0x1010107f
		strerr_warn5("tls_init: unable to set cipher", method && method < 7 ? "list: " : "suites: ",
				ciphers, ": ", sslerr_str, 0);
#else
		strerr_warn4("tls_init: unable to set cipherlist: ", ciphers, ": ", sslerr_str, 0);
#endif
		SSL_CTX_free(ctx);
		return ((SSL_CTX *) NULL);
	}
	if (SSL_CTX_use_certificate_chain_file(ctx, cert) != 1) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_CTX_use_PrivateKey_file: Unable to load private keys: ", sslerr_str, 0);
		SSL_CTX_free(ctx);
		return ((SSL_CTX *) NULL);
	}
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
	if (SSL_CTX_use_PrivateKey_file(ctx, cert, SSL_FILETYPE_PEM) != 1) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_CTX_use_PrivateKey_file: Unable to load private keys: ", sslerr_str, 0);
		SSL_CTX_free(ctx);
		return ((SSL_CTX *) NULL);
	}
#else
	if (SSL_CTX_use_RSAPrivateKey_file(ctx, cert, SSL_FILETYPE_PEM) != 1) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_CTX_use_RSAPrivateKey_file: Unable to load RSA private keys: ", sslerr_str, 0);
		SSL_CTX_free(ctx);
		return ((SSL_CTX *) NULL);
	}
#endif
	if (SSL_CTX_check_private_key(ctx) != 1) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn4("SSL_CTX_use_certificate_file: Unable to use private key: ", cert, ": ", sslerr_str, 0);
		SSL_CTX_free(ctx);
		return ((SSL_CTX *) NULL);
	}
	if (tmode == server || tmode == qsmtpd)
		set_rsa_dh(ctx);
	return (ctx);
}

SSL            *
tls_session(SSL_CTX *ctx, int fd)
{
	SSL            *myssl;
	BIO            *sbio;

	if (usessl != none)
		return ssl_t;
	if (!(myssl = SSL_new(ctx))) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("SSL_new: Unable to setup SSL session: ", sslerr_str, 0);
		return ((SSL *) NULL);
	}
	if (!(sbio = BIO_new_socket(fd, BIO_NOCLOSE))) {
		sslerr_str = (char *) myssl_error_str();
		strerr_warn2("BIO_new_socket: ", sslerr_str, 0);
		while (SSL_shutdown(myssl) == 0)
			usleep(100);
		SSL_free(myssl);
		return ((SSL *) NULL);
	}
	SSL_set_bio(myssl, sbio, sbio); /*- cannot fail */
	do_shutdown = 1;
	return (ssl_t = myssl);
}

const char     *
decode_ssl_error(int i)
{
	/*
	 * i =
	 * 0  The TLS/SSL handshake was not successful but was shut down
	 *    controlled and by the specifications of the TLS/SSL protocol.
	 *    Call SSL_get_error() with the return value ret to find out the
	 *    reason.
	 *
	 * 1  The TLS/SSL handshake was successfully completed, a TLS/SSL
	 *    connection has been established.
	 *
	 * <0 The TLS/SSL handshake was not successful because a fatal error
	 *    occurred either at the protocol level or a connection failure
	 *    occurred. The shutdown was not clean. It can also occur if action
	 *    is needed to continue the operation for nonblocking BIOs. Call
	 *    SSL_get_error() with the return value ret to find out the reason.
	 */
	switch (i)
	{
	case SSL_ERROR_NONE:
		return "no error";
	case SSL_ERROR_ZERO_RETURN:
		return "connection closed by TLS/SSL peer";
	case SSL_ERROR_WANT_READ:
		return "unprocessed data availabe for read";
	case SSL_ERROR_WANT_WRITE:
		return "unprocessed data availabe for write";
	case SSL_ERROR_WANT_CONNECT:
		return "TLS/SSL connect to be retried";
	case SSL_ERROR_WANT_ACCEPT:
		return "TLS/SSL accept to be retried";
	case SSL_ERROR_WANT_X509_LOOKUP:
		return "retry SSL_CTX_set_client_cert_cb() callback";
#if OPENSSL_VERSION_NUMBER >= 0x10100000L /*- openssl 1.1.0 */
	case SSL_ERROR_WANT_ASYNC:
		return "async engine still processing data";
	case SSL_ERROR_WANT_ASYNC_JOB:
		return "no async jobs available";
#endif
#if OPENSSL_VERSION_NUMBER >= 0x1010107f /*- openssl 1.1.1 */
	case SSL_ERROR_WANT_CLIENT_HELLO_CB:
		return "retry callback set by SSL_CTX_set_client_hello_cb()";
#endif
	case SSL_ERROR_SYSCALL:
		do_shutdown = 0;
		return "non-recoverable, fatal I/O error";
	case SSL_ERROR_SSL:
		do_shutdown = 0;
		return "non-recoverable, fatal protocol error";
	default:
		return ((char *) 0);
	}
}

int
tls_connect(int timeout, int rfd, int wfd, SSL *myssl, char *host)
{
	int             i, err;
	const char     *err_str;

	errno = 0;
	while (1) {
		if ((i = ssl_timeoutconn(timeout, rfd, wfd, myssl)) == 1) {
			if (host && check_cert(myssl, host)) {
				ssl_free();
				return -1;
			}
			if (ssl_rfd == -1) {
				ssl_rfd = rfd;
				SSL_set_rfd(myssl, ssl_rfd);
			}
			if (ssl_wfd == -1) {
				ssl_wfd = wfd;
				SSL_set_wfd(myssl, ssl_wfd);
			}
			usessl = client;
			return 0;
		}
		if ((err = SSL_get_error(myssl, i)) != SSL_ERROR_WANT_CONNECT)
			break;
	}
	switch (err)
	{
	case SSL_ERROR_SYSCALL:
	case SSL_ERROR_SSL:
		if (errno)
			strerr_warn1("SSL_connect: system err: ", &strerr_sys);
	}
	err_str = decode_ssl_error(err);
	if (err_str)
		strerr_warn2("SSL_connect: decoded err: ", err_str, 0);
	SSL_load_error_strings();
	/*- clear error stack */
	while ((err = ERR_get_error()))
		strerr_warn2("SSL_connect: TLS/SSL err: ", ERR_error_string(err, 0), 0);
	ssl_free();
	return i == 0 ? 1 : i;
}

int
tls_accept(int timeout, int rfd, int wfd, SSL *myssl)
{
	int             i, err;
	const char     *err_str;

	errno = 0;
	while (1) {
		if ((i = ssl_timeoutaccept(timeout, rfd, wfd, myssl)) == 1) {
			usessl = server;
			if (ssl_rfd == -1) {
				ssl_rfd = rfd;
				SSL_set_rfd(myssl, ssl_rfd);
			}
			if (ssl_wfd == -1) {
				ssl_wfd = wfd;
				SSL_set_wfd(myssl, ssl_wfd);
			}
			return 0;
		}
		if ((err = SSL_get_error(myssl, i)) != SSL_ERROR_WANT_ACCEPT)
			break;
	}
	switch (err)
	{
	case SSL_ERROR_SYSCALL:
	case SSL_ERROR_SSL:
		if (errno)
			strerr_warn1("SSL_accept: system err: ", &strerr_sys);
	}
	err_str = decode_ssl_error(err);
	if (err_str)
		strerr_warn2("SSL_accept: decoded err: ", err_str, 0);
	/*- clear error stack */
	while ((err = ERR_get_error()))
		strerr_warn2("SSL_accept: TLS/SSL err: ", ERR_error_string(err, 0), 0);
	ssl_free();
	return i == 0 ? 1 : i;
}

ssize_t
ssl_timeoutio(int (*fun) (), long t, int rfd, int wfd, SSL *myssl, char *buf, size_t len)
{
	int             n = 0;
	const long      end = t + time(NULL);

	do
	{
		fd_set          fds;
		struct timeval  tv;
		const int       r = buf ? fun(myssl, buf, len) : fun(myssl);

		if (r > 0)
			return r;
		if ((t = end - time(NULL)) < 0) {
			errno = ETIMEDOUT;
			return -1;
		}
		tv.tv_sec = t;
		tv.tv_usec = 0;
		FD_ZERO(&fds);
		switch (SSL_get_error(myssl, r))
		{
		default: /*- SSL_accept(), SSL_connect() will return here */
			return r; /*- some other error. See man SSL_read(3ossl), SSL_write(3ossl), etc */
		case SSL_ERROR_WANT_READ:
			if (errno == EAGAIN && usessl == client && fun == SSL_read && efd != -1)
				FD_SET(efd, &fds);
			FD_SET(rfd, &fds);
			n = select(efd != -1 && efd > rfd ? efd + 1 : rfd + 1, &fds, NULL, NULL, &tv);
			/*-
			 * this avoids deadlock in tcpclient when rfd becomes
			 * readable only when data is written to SSL..
			 * select will continue to wait for data on rfd.
			 * checking efd for input allows ssl_timeoutio() to
			 * return when data is available to be written to SSL when
			 * efd becomes available to be read for data that can
			 * be written to SSL.
			 */
			if (usessl == client && fun == SSL_read && efd != -1) {
				if (FD_ISSET(efd, &fds)) {
					errno = EAGAIN;
					return -1;
				}
			}
			break;
		case SSL_ERROR_WANT_WRITE:
			FD_SET(wfd, &fds);
			n = select(wfd + 1, NULL, &fds, NULL, &tv);
			break;
		}
		/*- n is the number of descriptors that changed status */
	} while (n > 0);
	if (!n)
		errno = ETIMEDOUT;
	return -1;
}

int
ssl_timeoutconn(long t, int rfd, int wfd, SSL *ssl)
{
	int             r, rfd_ndelay, wfd_ndelay;

	/*- get the current NDELAY flag for rfd, wfd */
	if ((rfd_ndelay = ndelay(rfd)) == -1 ||
			(wfd_ndelay = ndelay(wfd)) == -1)
		return -1;
	/*- if connection is established, keep NDELAY */
	if ((!rfd_ndelay && ndelay_on(rfd) == -1) || (!wfd_ndelay && ndelay_on(wfd) == -1))
		return -1;
	if ((r = ssl_timeoutio(SSL_connect, t, rfd, wfd, ssl, NULL, 0)) <= 0) {
		/*- restore status quo */
		if (!rfd_ndelay)
			ndelay_off(rfd);
		if (!wfd_ndelay)
			ndelay_off(wfd);
	} else
		SSL_set_mode(ssl, SSL_MODE_ENABLE_PARTIAL_WRITE);
	return r;
}

int
ssl_timeoutaccept(long t, int rfd, int wfd, SSL *ssl)
{
	int             r, rfd_ndelay, wfd_ndelay;

	/*- get the current NDELAY flag for rfd, wfd */
	if ((rfd_ndelay = ndelay(rfd)) == -1 ||
			(wfd_ndelay = ndelay(wfd)) == -1)
		return -1;
	/*- if connection is established, keep NDELAY */
	if ((!rfd_ndelay && ndelay_on(rfd) == -1) || (!wfd_ndelay && ndelay_on(wfd) == -1))
		return -1;
	if ((r = ssl_timeoutio(SSL_accept, t, rfd, wfd, ssl, NULL, 0)) <= 0) {
		if (!rfd_ndelay)
			ndelay_off(rfd);
		if (!wfd_ndelay)
			ndelay_off(wfd);
	} else {
		SSL_set_mode(ssl, SSL_MODE_ENABLE_PARTIAL_WRITE);
		usessl = server;
	}
	return r;
}

ssize_t
allwritessl(SSL *myssl, char *buf, size_t len)
{
	int             w;
	size_t          total = 0;

	while (len) {
		if ((w = SSL_write(myssl, buf, len)) == -1) {
			if (errno == error_intr)
				continue;
			return -1;	/*- note that some data may have been written */
		}
		if (w == 0)
			;	/*- luser's fault */
		buf += w;
		total += w;
		len -= w;
	}
	return total;
}

int
ssl_timeoutrehandshake(long t, int rfd, int wfd, SSL *ssl)
{
	int             r;

	SSL_renegotiate(ssl);
	r = ssl_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	if (r <= 0 || SSL_get_state(ssl) == SSL_ST_CONNECT)
#else
	if (r <= 0 || ssl->type == SSL_ST_CONNECT)
#endif
		return r;
	/*- this is for the server only */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
	SSL_set_accept_state(ssl);
#else
	ssl->state = SSL_ST_ACCEPT;
#endif
	return ssl_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
}

ssize_t
ssl_timeoutread(long t, int rfd, int wfd, SSL *myssl, char *buf, size_t len)
{
	ssize_t         n;

	if (!buf)
		return 0;
	if ((n = SSL_pending(myssl)))
		return (SSL_read(myssl, buf, n <= len ? n : len));
	return ssl_timeoutio(SSL_read, t, rfd, wfd, myssl, buf, len);
}

ssize_t
ssl_timeoutwrite(long t, int rfd, int wfd, SSL *myssl, char *buf, size_t len)
{
	if (!buf)
		return 0;
	return ssl_timeoutio((int (*)())allwritessl, t, rfd, wfd, myssl, buf, len);
}
#endif

int
translate(int rfd, int wfd, int clearout, int clearin, unsigned int iotimeout)
{
	struct taia     now, deadline;
	iopause_fd      iop[2];
	int             flagexitasap, iopl, counter, t;
	ssize_t         n, r;
	char            tbuf_clear[1024], tbuf_ssl[4096];

	flagexitasap = 0;
	while (!flagexitasap) { /*- main event loop to encrypt/decrypt SSL data */
		taia_now(&now);
		taia_uint(&deadline, iotimeout);
		taia_add(&deadline, &now, &deadline);

		/*- fill iopause struct */
		iopl = 2;
		iop[0].fd = rfd;
		iop[0].events = IOPAUSE_READ;
		iop[1].fd = clearin;
		iop[1].events = IOPAUSE_READ;

		/*- do iopause read */
		iopause(iop, iopl, &deadline, &now);
		if (iop[0].revents) { /*- encrypted data on rfd */
			/*-
			 * this for loop empties the SSL read queue. We use combination of
			 * two methods
			 * 1. Use SSL_has_pending() to keep on reading till the SSL read
			 *    queue is emtpy
			 * 2. We use a larger buffer for reading from SSL than the buffer
			 *    used for writing to SSL. We require this because the SSL read
			 *    queue length will be bigger than sizeof(tbuf_clear). So if we
			 *    write n bytes to SSL it is possible that the decrypted data is
			 *    larger than n.
			 */
			for (counter = 0;!flagexitasap;counter++) {
				t = 0;
				if ((n = tlsread(rfd, tbuf_ssl, sizeof(tbuf_ssl), iotimeout)) < 0) {
					/*
					 * tlsread will block on select till data is available
					 * in the SSL (rfd) buffer to be processed. It is possible
					 * that data becomes available on after data is available
					 * on clearin to be subsequently written to SSL (wfd).
					 * So we use a trick to add the file descriptor clearin
					 * to the fd set of select in ssl_timeoutread() using
					 * set_essential_fd() and return EAGAIN if there is data
					 * on clearin to be written to wfd.
					 * We set t=1 and break out of this loop to come back
					 * to the main event loop. The main event loop will then
					 * have iop[1].revents be true which will make the application
					 * process data on clearin
					 */
					if (errno == EAGAIN) {
						t = 1; /*- maybe data available on clearin */
						break;
					}
					strerr_warn1("translate: read network: ", &strerr_sys);
					return -1;
				} else
				if (!n) {
					flagexitasap = 1;
					break;
				}
				if ((r = allwrite(clearout, tbuf_ssl, n)) == -1) {
					strerr_warn1("translate: write clear channel: ", &strerr_sys);
					return -1;
				}
#ifdef TLS
				if (usessl != none && rfd == ssl_rfd) {
					if (!SSL_has_pending(ssl_t))
						break;
					if (counter > 10)
						usleep(100);
				} else
					break;
#else
				break;
#endif
			} /*- for (counter = 0;!flagexitasap;counter++) */
			/*-
			 * now continue the main event loop and process
			 * iop[1].revents to read data on clearin and write
			 * it to SSL
			 */
			if (t)
				continue;
		}
		if (iop[1].revents) { /*- un-encrypted data on clearin */
			if ((n = timeoutread(iotimeout, clearin, tbuf_clear, sizeof(tbuf_clear))) < 0) {
				strerr_warn1("translate: read clear channel: ", &strerr_sys);
				return -1;
			} else
			if (!n) {
				flagexitasap = 1;
				break;
			}
			if ((r = tlswrite(wfd, tbuf_clear, n, iotimeout)) == -1) {
				if (errno == EAGAIN)
					continue;
				strerr_warn1("translate: write network: ", &strerr_sys);
				return -1;
			}
		}
		if (!iop[0].revents && !iop[1].revents) {
			if (!iop[0].revents)
				strerr_warn1("timeout reached without input from network", 0);
			if (!iop[1].revents)
				strerr_warn1("timeout reached without output from child", 0);
			return -1;
		}
	} /*- while (!flagexitasap) */
	return 0;
}

ssize_t
tlsread(int fd, char *buf, size_t len, long timeout)
{
	ssize_t         r;

#ifdef HAVE_SSL
	if (usessl != none && fd == ssl_rfd) {
		if ((r = ssl_timeoutread(timeout, ssl_rfd, ssl_wfd, ssl_t, buf, len)) < 0) {
			if (errno == EAGAIN || errno == ETIMEDOUT)
				return -1;
			sslerr_str = (char *) myssl_error_str();
			if (sslerr_str && errno)
				STRERR_SYS2(r, strerr_tls, "ssl_err: ", sslerr_str)
			else
			if (sslerr_str)
				STRERR2(r, strerr_tls, "ssl_err: ", sslerr_str)
			else
			if (errno)
				STRERR2(r, strerr_tls, "sys_err: ", error_str(errno))
			else
				STRERR(r, strerr_tls, "tls/sys_err: Unknown error")
		}
	} else
		r = timeoutread(timeout, fd, buf, len);
#else
	r = timeoutread(timeout, fd, buf, len);
#endif
	return r;
}

ssize_t
tlswrite(int fd, char *buf, size_t len, long timeout)
{
	ssize_t         r;

#ifdef HAVE_SSL
	if (usessl != none && fd == ssl_wfd) {
		if ((r = ssl_timeoutwrite(timeout, ssl_rfd, ssl_wfd, ssl_t, buf, len)) < 0) {
			if (errno == EAGAIN || errno == ETIMEDOUT)
				return -1;
			sslerr_str = (char *) myssl_error_str();
			if (sslerr_str && errno)
				STRERR_SYS2(r, strerr_tls, "ssl_err: ", sslerr_str)
			else
			if (sslerr_str)
				STRERR2(r, strerr_tls, "ssl_err: ", sslerr_str)
			else
			if (errno)
				STRERR2(r, strerr_tls, "sys_err: ", error_str(errno))
			else
				STRERR(r, strerr_tls, "tls/sys_err: Unknown error")
		}
	} else
		r = timeoutwrite(timeout, fd, buf, len);
#else
	r = timeoutwrite(timeout, fd, buf, len);
#endif
	return r;
}

#ifndef	lint
void
getversion_tls_c()
{
	if (write(1, sccsid, 0) == -1)
		;
}
#endif

/*
 * $Log: tls.c,v $
 * Revision 1.9  2023-08-22 20:00:23+05:30  Cprogrammer
 * added get_tls_method function
 * use SSL_CTX_set_ciphersuites() for TLSv1_3 and above instead of SSL_CTX_set_cipher_list()
 * pass pointer to tls method in set_tls_method()
 * set default cipher PROFILE=SYSTEM only for TLSv1_2 and below
 * added get_tls_method function
 * added pointer to tls method variable as a new argument to tls_set_method()
 * corrected bug invalid cipher caused SIGSEGV
 * tlsclientmethod, tlsservermethod can have min:max as version
 * added sslvstr_to_method, sslmethod_to_version functions
 * set errno = EPROTO when protocol is unavailable
 * fixed few warnings without ssl errors
 * BUG. SSL_CTX_set_cipher_list incorrectly called instead of SSL_CTX_set_ciphersuites when method is auto
 * set min/max proto version only when min/max version variable is non-zero
 *
 * Revision 1.8  2023-08-20 22:33:36+05:30  Cprogrammer
 * store ssl, system error for tlsread, tlswrite in strerr_tls structure
 *
 * Revision 1.7  2023-02-15 16:55:41+05:30  Cprogrammer
 * self generate rsa/dh parameters if rsa/dh files are missing or unreadable
 *
 * Revision 1.6  2023-02-13 20:24:38+05:30  Cprogrammer
 * removed SSL_CTX_free in tls_session on SSL_new failure
 *
 * Revision 1.5  2023-01-12 19:07:55+05:30  Cprogrammer
 * added check for crlfile
 * restore ndelay if changed in ssl_timeoutconn, ssl_timeoutaccept
 * use SSL_pending, SSL_has_pending to read complete application data
 *
 * Revision 1.4  2023-01-07 12:53:05+05:30  Cprogrammer
 * replaced SSH_shutdown + SSL_free with ssl_free function
 *
 * Revision 1.3  2023-01-03 23:00:17+05:30  Cprogrammer
 * SSL_CTX_set_ecdh_auto supported only on openssl 1.0.2 and above
 *
 * Revision 1.2  2023-01-03 15:50:15+05:30  Cprogrammer
 * set default ciphers to "PROFILE=SYSTEM" to quell rpmlint warning
 *
 * Revision 1.1  2023-01-02 22:41:21+05:30  Cprogrammer
 * Initial revision
 *
 */
