/*
 * $Log: getEnvConfig.c,v $
 * Revision 1.1  2020-04-01 17:59:06+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "env.h"
#include "scan.h"

/*- getEnvConfigStr */
void
getEnvConfigStr(char **source, char *envname, char *defaultValue)
{
	if (!(*source = env_get(envname)))
		*source = defaultValue;
	return;
}

void
getEnvConfigInt(int *source, char *envname, int defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_int(value, source);
	return;
}

void
getEnvConfigLong(long *source, char *envname, long defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_long(value, source);
	return;
}

void
getEnvConfiguLong(unsigned long *source, char *envname, unsigned long defaultValue)
{
	char           *value;

	if (!(value = env_get(envname)))
		*source = defaultValue;
	else
		scan_ulong(value, source);
	return;
}

void
getversion_getEnvConfig_c()
{
	static char    *x = "$Id: getEnvConfig.c,v 1.1 2020-04-01 17:59:06+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
