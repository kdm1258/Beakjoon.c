#include <stdio.h>
#include <string.h>
#include <math.h>
int main (void){
    char str[81];
    int dp[81];
    int n = 0 ;
    int countLong = 2;
    int ans = 1;

    scanf("%d", &n); //�迭 ���� �Է¹ޱ�
    scanf("%s", str);
    char* pnt = str;

    if((strstr(str,"longlong")) == NULL){
        printf("%d",1);
    }
    else{
        //Dynamic programing
            dp[1] = 1; //long�� �ϳ�����ִ� ���ڿ����� ������ ��ȯ�� 1����,
            dp[2] = 2; //longlong�� �ѹ� ��� �ִ� ���ڿ����� ������ ��ȯ�� 2�����̴�.

            for (int i = 3 ; i <= 80 ; i++){
                dp[i] = dp[i-1]+ dp[i-2];
            }
        while((pnt=strstr(pnt,"longlong")) != NULL){
            if(strncmp((pnt+=4), "longlong",8)==0){   //longlong�� ������ +4 �� ���� ���������� �ϴ� ��ġ��
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
