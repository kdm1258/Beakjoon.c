#include <stdio.h>
int main(void){
    int arr[10000] = {0, 1, 2, 4};
    int cnt ;
    int n;
    int sol[100];
    scanf("%d", &cnt);
    for (int j = 0 ; j < cnt ; j++){
        scanf("%d", &sol[j]);
    }
    for (int j = 0 ; j < cnt ; j++){
        if (sol[j] == 1)
            printf("%d\n",1);
        else if (sol[j] == 2)
            printf("%d\n",2);
        else if (sol[j] == 3)
            printf("%d\n",4);
        else{
            for (int i = 4 ; i <= sol[j] ; i++){
                arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
            }
            printf("%d\n",arr[sol[j]]);
        }
    }
}
