#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termio.h>
#include <unistd.h>
#include <string.h>

int getch(void);
void print_puzz(int puzzle[4][4]);
void print_shuff(int shuffle[16]);

int main(int argc, char *argv[]){
	srand(time(NULL));

	int sample1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
	int sample[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
	int cnt = 0,cnt1 = 0, cnt2 = 0;
	int control;
	
	
	if (strcmp(argv[1],"1")==0){

		int puzzle[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};

		print_puzz(puzzle);
		while(1){
			control = getch();
			if (control == 'q'){
				break;
			}
			else{
				cnt = 0;

				for (int i = 0 ; i < 4 ; i++){
					for (int j = 0 ; j < 4 ; j++){
						if ((puzzle[i][j] == 0)&&(cnt == 0)){
							
							if ((control == 'i') && (i!=3)){
								puzzle[i][j] = puzzle[i+1][j];
								puzzle[i+1][j] = 0;
								cnt++;
								break;
							}
							
							else if ((control == 'j') && (j!=3)){
								puzzle[i][j] = puzzle[i][j+1];
								puzzle[i][j+1] = 0;
								cnt++;
								break;
							}
							
							else if ((control == 'k') && (i!=0)){
								puzzle[i][j] = puzzle[i-1][j];
								puzzle[i-1][j] = 0;
								cnt++;
								break;
							}
							
							else if ((control == 'l') && (j!=0)){
								puzzle[i][j] = puzzle[i][j-1];
								puzzle[i][j-1] = 0;
								cnt++;
								break;
							}
						}
					}
				}

				cnt2 = 0;	
				for (int i = 0 ; i < 4 ; i++){
					for	(int j = 0 ; j < 4 ; j++){
						if (puzzle[i][j] != sample[i][j]){
							cnt2++;
						}
					}
				}
				print_puzz(puzzle);
		
		
				if ((cnt2 == 0)&&(cnt1 !=0)){
					printf("\n\n			축하합니다.\n");
					sleep(3);
					break;
				}
				cnt1++;
			}
		}
	}
	
	else if (strcmp(argv[1],"2")==0){

		int shuffle[16] = {0};
	
		for (int i = 0 ; i < 16 ; i++){
			shuffle[i] = rand() % 16 ;
			for (int j = 0 ; j < i ; j++){
				if (shuffle[j] == shuffle[i]){
					i--;
					break;
				}
			}
		}
	
		print_shuff(shuffle);
		while(1){
			control = getch();
			if (control == 'q'){
				break;
			}
			else{
				cnt = 0;

				for (int i = 0 ; i < 16 ; i++){
					
					if ((shuffle[i] == 0)&&(cnt == 0)){
							
							if ((control == 'i') && (i<=11)){
								shuffle[i] = shuffle[i+4];
								shuffle[i+4] = 0;
								cnt++;
								break;
							}
							
							else if ((control == 'j') && (i%4 != 3)){
								shuffle[i] = shuffle[i+1];
								shuffle[i+1]= 0;
								cnt++;
								break;
							}
							
							else if ((control == 'k') && (i>=4)){
								shuffle[i] = shuffle[i-4];
								shuffle[i-4] = 0;
								cnt++;
								break;
							}
							
							else if ((control == 'l') && (i%4 != 0)){
								shuffle[i] = shuffle[i-1];
								shuffle[i-1] = 0;
								cnt++;
								break;
							}
						}
					}
				

				cnt2 = 0;	
				for (int i = 0 ; i < 16 ; i++){
					if (shuffle[i] != sample1[i]){
						cnt2++;
					}
					
				}
				print_shuff(shuffle);
		
		
				if ((cnt2 == 0)&&(cnt1 !=0)){
					printf("\n\n			축하합니다.\n");
					sleep(3);
					break;
				}
				cnt1++;
			}
		}


	}
}

int getch(void) {

	int ch;

	struct termios buf;
	struct termios save;
	tcgetattr(0, &save);
	buf = save;
	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;
	tcsetattr(0, TCSAFLUSH, &buf);
	ch=getchar();
	tcsetattr(0, TCSAFLUSH, &save);

	return ch;

}
void print_puzz(int puzzle[4][4]){
	
	system("clear");
	for (int i = 0 ; i < 4 ; i++){
		printf("\n\n");
		printf("		");
		for (int j = 0 ; j < 4 ; j++){
			if (puzzle[i][j] == 0){
				printf("       ");
			}
			else{	
				printf("%7d",puzzle[i][j]);
			}
		}
		
	}	
}
void print_shuff(int shuffle[16]){
	
	int cnt = 0;
	system("clear");
	printf("		");
	for (int i = 0 ; i <16 ; i++){
		if (cnt %4 == 0){
			printf("\n\n");
			printf("		");
		}
		if (shuffle[i] == 0){
			printf("       ");
		}
		else{	
			printf("%7d", shuffle[i]);
		}
		cnt++;
	}
		
}

