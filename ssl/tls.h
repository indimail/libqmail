/*
 * $Id: tls.h,v 1.1 2023-01-02 22:41:27+05:30 Cprogrammer Exp mbhangui $
 */
#ifndef _TLS_H
#define _TLS_H
#include <sys/types.h>
#if defined(HAVE_SSL) || defined(TLS)
#include <openssl/ssl.h>
#endif

enum tlsmode  {none = 0, client = 1, server = 2, qsmtpd = 3, qremote = 4};
enum starttls {smtp, pop3, unknown};

ssize_t         tlsread(int, char *, size_t, long);
ssize_t         tlswrite(int, char *, size_t, long);
#if defined(HAVE_SSL) || defined(TLS)
SSL_CTX        *tls_init(char *, char *, char *, char *, char *, enum tlsmode);
SSL_CTX        *set_tls_method(char *, enum tlsmode, int *);
void            set_rsa_dh(SSL_CTX *);
SSL            *tls_session(SSL_CTX *, int);
int             tls_connect(int, int, int, SSL *, char *);
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
void            set_certdir(char *s);
#if OPENSSL_VERSION_NUMBER < 0x30000000L
RSA            *tmp_rsa_cb(SSL *, int, int);
DH             *tmp_dh_cb(SSL *, int, int);
#else
EVP_PKEY       *get_rsakey(int, int, char *);
EVP_PKEY       *get_dhkey(int, int, char *);
#endif
#endif /*- #if defined(HAVE_SSL) || defined(TLS) */

#endif /*- _TLS_H */

/*
 * $Log: tls.h,v $
 * Revision 1.1  2023-01-02 22:41:27+05:30  Cprogrammer
 * Initial revision
 *
 */
