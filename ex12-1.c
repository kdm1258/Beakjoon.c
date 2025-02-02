#include <stdio.h>
#define N 10
int main(void)
{
	int a[N];
	int b[N][N];
	printf("sizeof(a[N-1]) : %ld\n",sizeof(a[N-1]));
	printf("sizeof(a) : %ld\n",sizeof(a));
	printf("sizeof(b[N-1][N-1]) : %ld\n",sizeof(b[N-1][N-1]));
	printf("sizeof(b[N-1]) : %ld\n",sizeof(b[N-1]));
	printf("sizeof(b) : %ld\n",sizeof(b));
	return 0;
}
