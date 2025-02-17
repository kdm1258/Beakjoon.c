#include <stdio.h>
void func(int n, int arr[10000]);
int main(void){
    int arr[100000] = {0};
    for (int i = 1 ; i <=10000 ; i++){
        func(i, arr);
    //    printf("%d\n", i);
    }
    for (int i = 0 ; i <=10000 ; i++){
        if (arr[i] == 0){
            printf("%d\n",i+1);
        }
    }

}
void func(int n, int arr[10000]){
    int tmp = n;
    while (n != 0){
        tmp += n % 10;
        n /= 10;
    }
    arr[tmp-1] = 1;

}
