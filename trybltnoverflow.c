int
main(int argc, char **argv)
{
	unsigned int i;

	if (__builtin_add_overflow(1, 2, &i) || __builtin_mul_overflow(1, 2, &i))
		return 1;
	return 0;
}
