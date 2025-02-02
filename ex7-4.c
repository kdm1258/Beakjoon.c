#include <stdio.h>
int main(void)
{
	char temp;
	char change;

	printf("알파벳 문자를 입력하세요: ");
	scanf("%c", &temp);

	if (temp <= 90 && temp >= 65){
		change = temp - 65 + 97;
		printf("변환된 문자는 %c입니다.", change);
	}
	
	else if ( temp >= 97 && temp <=122){
		change = temp - 97 + 65 ;
		printf("변환된 문자는 %c입니다.",change);
	}

	else
		printf("잘못된 입력");

}
