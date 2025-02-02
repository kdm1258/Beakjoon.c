#include <stdio.h>
#include <stdlib.h>
void mygets(char[]);
int main(void){

	char input[100];
	mygets(input);
	puts(input);
	printf("입력끝");
	return 0;

}
void mygets(char input[] ){
	int i = 0;
	char temp;
	while(1){
		
		temp = getchar();
		
		if (temp == '\n'){
			break;
		}
		else{
			input[i] = temp;
		}
		i++;
	}
	input[i] = 0;
}

