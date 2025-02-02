#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("CHAR_MAx : %d\n", CHAR_MAX);

	printf("SCHAR_MIN : %d\n", SCHAR_MIN);
	printf("SCHAR_MAX : %d\n", SCHAR_MAX);

	printf("UCHAR_MAx : %u\n", UCHAR_MAX); // unsigned char은 %d %u 상관없이 받을 수 있다.

	printf("SHRT_MIN : %hd\n", SHRT_MIN );
	printf("SHRT_MAX : %hd\n", SHRT_MAX ); // short %hd %d 노상관

	printf("USHRT_MAX  : %d\n", USHRT_MAX );

	printf("INT_MIN : %d\n", INT_MIN);
	printf("INT_MAX : %d\n", INT_MAX);

	printf("UINT_MAX : %u\n", UINT_MAX );

	printf("LONG_MIN : %ld\n", LONG_MIN);
	printf("LONG_MAx : %ld\n", LONG_MAX);

	printf("ULONG_MAx : %lu\n", ULONG_MAX);

	printf("LLONG_MIN : %lld\n", LLONG_MIN );
	printf("LLONG_MAx : %lld\n", LLONG_MAX);

	printf("ULLONG_MAx : %llu\n", ULLONG_MAX);
	
	return 0;

}
