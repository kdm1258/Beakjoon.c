#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int main(void){

	char booklist[5][50] = {"Cygwin과 함께 배우는 C 프로그래밍", "C 99", "A book on C", "C 프로그래밍", "자바 프로그래밍"};

	int i = 0;
	char temp[50];
	char *p;
	
	mygets(temp);
	for (i = 0 ; i < 5 ; i++){
		
		p = strstr(booklist[i], temp);
		if (p == NULL){
			continue;
		}
		else
		printf("%s\n",booklist[i]);

	}

}
