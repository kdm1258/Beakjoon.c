#include <stdio.h>
#include <string.h>
#include <math.h>
int main (void){
    char str[81];
    int dp[81];
    int n = 0 ;
    int countLong = 2;
    int ans = 1;

    scanf("%d", &n); //배열 길이 입력받기
    scanf("%s", str);
    char* pnt = str;

    if((strstr(str,"longlong")) == NULL){
        printf("%d",1);
    }
    else{
        //Dynamic programing
            dp[1] = 1; //long이 하나들어있는 문자열에서 가능한 변환은 1가지,
            dp[2] = 2; //longlong이 한번 들어 있는 문자열에서 가능한 변환은 2가지이다.

            for (int i = 3 ; i <= 80 ; i++){
                dp[i] = dp[i-1]+ dp[i-2];
            }
        while((pnt=strstr(pnt,"longlong")) != NULL){
            if(strncmp((pnt+=4), "longlong",8)==0){   //longlong의 포인터 +4 의 값을 시작점으로 하는 위치에
                countLong++;
            }
            else if(strncmp((pnt), "long",4)==0){
                ans*=dp[countLong];
                countLong = 2;
            }
        }
        printf("%d",ans);
    }

}
