/*
 * $Log: getEnvConfig.h,v $
 * Revision 1.3  2024-05-09 23:46:19+05:30  mbhangui
 * fix discarded-qualifier compiler warnings
 *
 * Revision 1.2  2022-04-17 08:19:34+05:30  Cprogrammer
 * added getEnvConfigDouble()
 *
 * Revision 1.1  2020-04-01 17:59:16+05:30  Cprogrammer
 * Initial revision
 *
 * Revision 1.1  2019-04-13 23:39:27+05:30  Cprogrammer
 * getEnvConfig.h
 *
 */
#ifndef GETENVCONFIGSTR_H
#define GETENVCONFIGSTR_H

void            getEnvConfigStr(char **, const char *, char *);
void            getEnvConfigInt(int *, const char *, int);
void            getEnvConfigLong(long *, const char *, long);
void            getEnvConfiguLong(unsigned long *, const char *, unsigned long);
void            getEnvConfigDouble(double *, const char *, double);

#endif /*- GETENVCONFIGSTR_H */
