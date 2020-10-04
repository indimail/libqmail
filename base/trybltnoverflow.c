/*
 * $Log: trybltnoverflow.c,v $
 * Revision 1.1  2020-05-14 11:07:18+05:30  Cprogrammer
 * Initial revision
 *
 */
int
main(int argc, char **argv)
{
	unsigned int    a = 0x80000000, b = 0x80000000, c;

	return !__builtin_add_overflow(a, b, &c) && !__builtin_mul_overflow(a, b, &c);
}
