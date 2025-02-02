#include <stdio.h>
int main(void){

	int width = 0 , height = 0;
	printf("사각형의 너비를 입력하세요. : ");
	scanf("%d", &width);
	printf("사각형의 높이를 입력하세요. : ");
	scanf("%d", &height);

	for (int j = 1 ; j <= height ; j++){
		for (int i = 1 ; i <= width ; i++){
			printf("#");
		}
	printf("\n");
	}
}
