#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void comp(int arr[3][2]);
int compare(const int* a, const int* b) {
	if (*a > *b) {
		return 1; //꼭 1이 아니라 양수이기만 하면 된다.
	}
	else {
		return -1; //음수는 자리를 바꾸지 않는다. 꼭 -1이 아니라 음수이기만 하면 된다.
	}
}

int main(void){
    int p[3]; // 문제를 맞춘 개수
    int y[3]; // 학번
    char s[3][5]; //성

    scanf("%d %d %s",&p[0], &y[0], s[0]);
    scanf("%d %d %s",&p[1], &y[1], s[1]);
    scanf("%d %d %s",&p[2], &y[2], s[2]);
    for (int i = 0 ; i <3 ; i++){
        y[i] %= 100;
    }
    qsort(y,3,sizeof(int),compare);
    printf("%d%d%d\n",y[0],y[1],y[2]);

    int info[3][2] ={};
    for (int i = 0 ; i < 3 ; i++){
        info[i][0] = p[i];
        info[i][1] = s[i][0];    //성의 첫 문자만 사용하기때문에 첫문자 분리
    }
    comp(info);
    return 0;
}
void comp(int arr[3][2]){
    int tmpI;
    char tmpC;
    for (int i = 0 ; i < 2 ; i++){
        for (int j = 0 ; j < 2 ; j++){
            if (arr[j][0] < arr[j+1][0]){
                tmpI = arr[j][0];
                arr[j][0] = arr[j+1][0];
                arr[j+1][0] = tmpI;

                tmpC = arr[j][1];
                arr[j][1] = arr[j+1][1];
                arr[j+1][1] = tmpC;
            }
        }
    }
    printf("%c%c%c",arr[0][1],arr[1][1],arr[2][1]); //버블정렬을 이용하여 2차원 배열 정렬
}
