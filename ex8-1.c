#include <stdio.h>
int main(void){
	
	int num, i, j ;
	printf("단수를 입력해 주세요 : ");
	scanf("%d", &num);

	for (i = num ; i <= 9 ; i++){
		for ( j = 1 ; j <=9 ; j++){
			printf("%d x %d = %d\n",i,j,i*j);
		}
		printf("\n");
	}

}
