#include <stdio.h>
long double power_of_2(int n)
{
	if (n==0)
		return 1;
	else if (n>0)
	{
		return (2.0 * power_of_2(n-1));
	}
	else
	{
			return(power_of_2(n+1)/2.0);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%LF",power_of_2(n));
	return 0 ;
}
