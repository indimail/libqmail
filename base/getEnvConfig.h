/*
 * $Log: getEnvConfig.h,v $
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

void            getEnvConfigStr(char **, char *, char *);
void            getEnvConfigInt(int *, char *, int);
void            getEnvConfigLong(long *, char *, long);
void            getEnvConfiguLong(unsigned long *, char *, unsigned long);
void            getEnvConfigDouble(double *, char *, double);

#endif /*- GETENVCONFIGSTR_H */
