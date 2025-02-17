#include <stdio.h>
#include <stdlib.h>


int func(int, int *);
int main(void){

    int n,a = 0;
    scanf("%d", &n);
    int size = 1000000;
    int *arr = (int*)malloc(sizeof(int) * size);
    arr[1] = 0;
    arr[0] = 10000;

    if (n == 1)
        printf("%d",0);
    else{
        for (int i = 2 ; i <= n ; i++){
            a = func(i, arr);
        }
        printf("%d", a);
    }
}

int func(int n, int *arr){
    int tmp = arr[n-1];
    if (tmp > arr[n/2] && (n%2==0)){
        tmp = arr[n/2];
    }
    if ((tmp > arr[n/3]) && (n%3==0)){
        tmp = arr[n/3];
    }
    arr[n] = tmp + 1;
    return arr[n];
}
