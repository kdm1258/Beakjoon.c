#include <stdio.h>
int main(void){
    int arr[100000] = {0};
    int n = 1;
    arr[1] = 1;
    arr[2] = 2;
    
    scanf("%d",&n);
    if (n==1) printf("%d",1);
    else if (n==2) printf("%d",2);
    else{
        for (int i =3 ; i <= n ; i++){
            arr[i] = (arr[i-1] + arr[i-2])%10007;  #15번째줄에서 나누면 그전에 값이 너무 커져 다른값으로 변함
        }
        printf("%d",arr[n]);
    }
    return 0;
}
