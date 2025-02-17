#include <stdio.h>
int main(void){
    int a ,b ;

    scanf("%d", &a);
    scanf("%d", &b);
    char arr[1000000] = {1, 1, 0};

    for (int i = 2 ; i <= b ; i++){
        for (int j = 2 ; i * j <= b ; j++){
            arr[i*j] = 1;
        }
    }

    for ( int i = a ; i <= b ; i++){
        if (arr[i] == 0){
            printf("%d\n",i);
        }
    }
}
