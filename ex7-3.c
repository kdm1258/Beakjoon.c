#include <stdio.h>
int main(void)
{
	int n = 0, sum = 0 ;
	printf("정수를 입력하세요 : ");
	scanf("%d", &n);

	if ( n >= 0){
		while ( n > 0 ){
			if (n%2==0){
				sum += n ;
			}
			--n;
		}
		printf("%d\n",sum);
	}
		        
}
