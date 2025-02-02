#include <stdio.h>
int main(void)
{
	int num, a, b ;

	printf("3자리 정수를 입력하세요. :");
	scanf("%d", &num);

	a = num / 100;
	b = num % 10;

	printf("백의 자리 숫자 : %d\n",a);
	printf("일의 자리 숫자 : %d\n",b);
}
