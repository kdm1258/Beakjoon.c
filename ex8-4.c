#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	int cnt = 1;
	srand(time(NULL));
	while ( cnt <=10 ){
		printf("%d\n",  rand());
		cnt++ ;
	}

}
