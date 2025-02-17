#include <stdio.h>
int main(void){

    int n = 0;
    int j , jj = 0;
    int temp = 0;
    int sum = 0;
    scanf("%d", &n);

    for ( j = 1 ; j <= n ; j++){
        sum = j;
        jj = j;
        while(jj != 0){
                temp = jj % 10 ;
                jj /= 10;
                sum += temp;
        }
        if (n == sum){
            printf("%d",j);
            break ;
        }
    }
    if (n + 1 == j){
        printf("%d",0);
    }
}
