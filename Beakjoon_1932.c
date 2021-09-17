#include <stdio.h>
#define N 500
void func(int i, int j, int arr[N][N]);

int main(void){

    int n = 0;
    int tmp = 0;
    scanf("%d", &n);
    int arr[N][N] = {0};

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j <= i ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1 ; i < n ; i++){
        for (int j = 0 ; j <= i ; j++){
            func(i, j, arr);
        }
    }
    for (int i = 0 ; i < n ; i++){
        if (tmp < arr[n-1][i]){
            tmp = arr[n-1][i];
        }
    }
    printf("%d", tmp);
}

void func(int i, int j, int arr[N][N]){
    if (j == 0){
        arr[i][j] += arr[i-1][j];
    }
    else if (j == i){
        arr[i][j] += arr[i-1][j-1];
    }
    else{
        if (arr[i-1][j-1] > arr[i-1][j]){
            arr[i][j] += arr[i-1][j-1];
        }
        else{
            arr[i][j] += arr[i-1][j];
        }
    }
    return ;
}
