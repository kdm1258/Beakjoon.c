#include <stdio.h>
int main(void){

    int num = 0, temp = 0, cnt = 0, sum = 0, i= 0;
    scanf("%d", &num);

    int arr[num];
    while(cnt < num){

        scanf("%d", &temp);
        if (temp != 0){
            arr[i] = temp;
        i++;
        }
        else{
            i--;
            arr[i] = 0;
        }
        cnt++;
    }
    for ( i + 1 ; i <= cnt ; i++){
        arr[i] = 0;
    }
    for ( int i = 0 ; i < num ; i++){
        sum += arr[i];
    }
    printf("%d", sum);
}
