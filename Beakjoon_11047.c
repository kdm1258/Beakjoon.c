#include <stdio.h>
int main(void){

    int cnt = 0;
    int N;
    int K;
    int tmp;
    scanf("%d %d",&N, &K);
    int arr[N];
    for (int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
    }
    while(K != 0){

        tmp = arr[0];
        for (int i = N - 1 ; 0 <= i ; i--){
            if ((arr[i] <= K) && (tmp <= arr[i])){
                tmp = arr[i];
            }
        }
        cnt += (K / tmp);
        K %= tmp;
    }
    printf("%d", cnt);
}
