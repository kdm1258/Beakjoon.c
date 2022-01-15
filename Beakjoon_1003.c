#include <stdio.h>
int main(void){
    int arr[100000][2] = {0};
    arr[0][0] = 1, arr[0][1] = 0;
    arr[1][0] = 0, arr[1][1] = 1;


    int n,input[1000];
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &input[i]);
    }
    for (int i = 0 ; i<n; i++){
        if (input[i] == 0) {
            printf("%d %d\n",arr[0][0],arr[0][1]);
        }
        else if (input[i] == 1) {
            printf("%d %d\n",arr[1][0], arr[1][1]);
        }
        else{
            for (int j = 2 ; j <= input[i] ; j++){
                arr[j][0] = arr[j-1][0] + arr[j-2][0];
                arr[j][1] = arr[j-1][1] + arr[j-2][1];
            }
            printf("%d %d\n",arr[input[i]][0],arr[input[i]][1]);
        }
    }

}
