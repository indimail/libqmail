/*
 * $Log: getEnvConfig.c,v $
 * Revision 1.2  2022-04-17 08:19:24+05:30  Cprogrammer
 * added getEnvConfigDouble()
 *
 * Revision 1.1  2020-04-01 17:59:06+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "env.h"
#include "scan.h"
#include "getEnvConfig.h"

/*- getEnvConfigStr */
void
getEnvConfigStr(char **source, const char *envname, char *defaultValue)
{
	if (!(*source = env_get(envname)))
		*source = defaultValue;
	return;
}

void
getEnvConfigInt(int *source, const char *envname, int defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_int(value, source);
	return;
}

void
getEnvConfigLong(long *source, const char *envname, long defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_long(value, source);
	return;
}

void
getEnvConfiguLong(unsigned long *source, const char *envname, unsigned long defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_ulong(value, source);
	return;
}

void
getEnvConfigDouble(double *source, const char *envname, double defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_double(value, source);
	return;
}

void
getversion_getEnvConfig_c()
{
	const char     *x = "$Id: getEnvConfig.c,v 1.2 2022-04-17 08:19:24+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
