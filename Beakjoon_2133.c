#include <stdio.h>
int main(void){
    int arr[31] = {0};
    arr[0] = 1;
    arr[2] = 3;

    int n = 0;
    scanf("%d", &n);
    if (n%2 != 0){
        printf("%d",0);
    }
    else if (n==2){
        printf("%d",3);
    }
    else{
        for (int i = 4 ; i <= n ; i+=2){
			 	arr[i] += arr[i-2] * 3 ;
			for (int j = i-4 ; j>=0 ; j-=2){
				arr[i] += arr[j] * 2;
			}
        }
        printf("%d", arr[n]);
    }
}
