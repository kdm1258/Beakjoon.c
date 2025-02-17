#include <stdio.h>
int main(void){

    int n = 0;
        scanf("%d",&n);
        int num[n];
        int temp;


        for (int i = 0 ; i <= n - 1 ; i++){
            scanf("%d",&num[i]);
        }

        for (int i = 0 ; i <= n - 1 ; i++){

            for (int j = 0 ; j <= n - i - 2 ; j++){


                if (num[j] > num[j + 1]){
                    temp = num[j];
                    num[j] = num[j + 1];
                    num[j + 1] = temp;
                }
            }
        }
        for (int j = 0 ; j <= n -1 ; j++){
            printf("%d\n",num[j]);
        }

}
