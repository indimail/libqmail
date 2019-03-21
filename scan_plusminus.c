#include "scan.h"

unsigned int
scan_plusminus(char *src, signed int *dest)
{
	*dest = 1;
	switch (*src)
	{
	case '-':
		*dest = -1;
	case '+':
		return 1;
	}
	return 0;
}
