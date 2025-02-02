#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	int secret , choice ;

	printf("==========가위 바위 보 게임을 시작합니다==========\n");
	
	srand(time(NULL));
	while (1){
		secret = rand() % 3;
		printf("\n\n가위(s) 바위(r) 보(p) 를 선택하세요.( 게임종료 : 9 )\n>>> ");
		choice = getchar(); 
		getchar();	
	
		if (choice == 's' || choice == 'S'){
			if (secret == 0)
				printf("당신은 가위를 냈고 컴퓨터는 가위를 냈습니다.\n당신은 비겼습니다.\n");
			else if (secret == 1 )
				printf("당신은 가위를 냈고 컴퓨터는 바위를 냈습니다.\n당신은 졌습니다.\n");
			else
				printf("당신은 가위를 냈고 컴퓨터는 보를 냈습니다.\n당신이 이겼습니다.\n");
				
		}
		else if (choice == 'r' || choice == 'R'){
			if (secret == 0)
				printf("당신은 바위를 냈고 컴퓨터는 가위를 냈습니다.\n당신이 이겼습니다.\n");
			else if (secret == 1 )
				printf("당신은 바위를 냈고 컴퓨터는 바위를 냈습니다.\n당신은 비겼습니다.\n");
			else
				printf("당신은 바위를 냈고 컴퓨터는 보를 냈습니다.\n당신은 졌습니다.\n");
		}
		else if (choice == 'p' || choice == 'P'){
			if (secret == 0)
				printf("당신은 보를 냈고 컴퓨터는 가위를 냈습니다.\n당신은 졌습니다.\n");
			else if (secret == 1 )
				printf("당신은 보를 냈고 컴퓨터는 바위를 냈습니다.\n당신이 이겼습니다.\n");
			else
				printf("당신은 보를 냈고 컴퓨터는 보를 냈습니다.\n당신은 비겼습니다.\n");
		}
		else if (choice == '9'){
			printf("=====================게임 종료====================\n");
			break;
		}
		else{
			printf("잘못된 입력입니다.\n");
			getchar();	
			continue;
			}
	}
	return 0;
}
