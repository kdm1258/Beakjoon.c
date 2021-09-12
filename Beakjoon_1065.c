#include <stdio.h>
int main(void){
    int a, n, num, cnt = 0, temp1, temp2, temp3;
    scanf("%d" , &n);

    for (int i = 1 ; i <= n ; i++){

        if (i < 100){
            cnt++;
        }
        else{
            a = i;
            temp1 = a % 10 ;
            a /= 10;
            temp2 = a % 10;

            temp3 = temp2 - temp1;
            while (a){
                a /= 10;
                if ((temp2 + temp3) != (a % 10)){
                    break ;
                }
            }
            if (a == 0){
                cnt++;
            }
        }

    }
    printf("%d", cnt);
}
