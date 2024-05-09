/*
 * $Id: tls.h,v 1.5 2024-05-09 23:50:05+05:30 mbhangui Exp mbhangui $
 */
#ifndef _TLS_H
#define _TLS_H
#include <sys/types.h>
#if defined(HAVE_SSL) || defined(TLS)
#include <openssl/ssl.h>
#endif
#include <strerr.h>

enum tlsmode  {none = 0, client = 1, server = 2, qsmtpd = 3, qremote = 4};
enum starttls {smtp, pop3, unknown};
extern struct strerr strerr_tls;

ssize_t         tlsread(int, char *, size_t, long);
ssize_t         tlswrite(int, char *, size_t, long);
#if defined(HAVE_SSL) || defined(TLS)
SSL_CTX        *tls_init(const char *, const char *, const char *, const char *, const char *, enum tlsmode);
int             get_tls_method(const char *);
int             sslvstr_to_method(const char *);
int             sslmethod_to_version(int);
SSL_CTX        *set_tls_method(const char *, int *, enum tlsmode, int *);
void            set_rsa_dh(SSL_CTX *);
SSL            *tls_session(SSL_CTX *, int);
int             tls_connect(int, int, int, SSL *, const char *);
int             tls_accept(int, int, int, SSL *);
void            ssl_free();
int             translate(int, int, int, int, unsigned int);
ssize_t         allwritessl(SSL *, char *, size_t);
ssize_t         ssl_timeoutio(int (*fun) (), long, int, int, SSL *, char *, size_t);
int             ssl_timeoutconn(long, int, int, SSL *);
int             ssl_timeoutaccept(long, int, int, SSL *);
ssize_t         ssl_timeoutread(long, int, int, SSL *, char *, size_t);
ssize_t         ssl_timeoutwrite(long, int, int, SSL *, char *, size_t);
int             ssl_timeoutrehandshake(long, int, int, SSL *);
const char     *myssl_error_str();
const char     *myssl_error();
void            set_essential_fd(int fd);
void            set_ssl_fd(SSL *, int, int);
void            set_certdir(const char *s);
#if OPENSSL_VERSION_NUMBER < 0x30000000L
RSA            *tmp_rsa_cb(SSL *, int, int);
DH             *tmp_dh_cb(SSL *, int, int);
#else
EVP_PKEY       *get_rsakey(int, int, const char *);
EVP_PKEY       *get_dhkey(int, int, const char *);
#endif
#endif /*- #if defined(HAVE_SSL) || defined(TLS) */

#endif /*- _TLS_H */

/*
 * $Log: tls.h,v $
 * Revision 1.5  2024-05-09 23:50:05+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.4  2023-08-22 00:57:26+05:30  Cprogrammer
 * added sslvstr_to_method, sslmethod_to_version functions
 *
 * Revision 1.3  2023-08-19 12:06:52+05:30  Cprogrammer
 * added get_tls_method function
 * added pointer to tls method variable as a new argument to tls_set_method()
 *
 * Revision 1.2  2023-08-06 11:15:39+05:30  Cprogrammer
 * store ssl, system error for tlsread, tlswrite in strerr_tls structure
 *
 * Revision 1.1  2023-01-02 22:41:27+05:30  Cprogrammer
 * Initial revision
 *
 */
