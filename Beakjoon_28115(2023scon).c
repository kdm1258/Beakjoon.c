#include <stdio.h>
int main(void){
    int arr[100000] = {0};
    int n=0;
    scanf("%d",&n);
    for (int i = 0 ; i<n ; i++){
        scanf("%d", &arr[i]);
    }
    if (n<=2){        //n이 2 이하일 경우 무조건 등차수열이 성립된다.
        printf("YES\n");
        for (int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]*2);
        }
        printf("\n");
        for (int i = 0 ; i < n ; i++){
            printf("%d ",arr[i]*(-1));
        }
        return 0;
    }
    int tmp = arr[1] - arr[0];      //모든 원자에 대하여 arr[i+1] - arr[i]가 성립하여야 등차수열이라고 말할 수 있다. 
    for (int i = 1 ; i<n-1 ; i++){  // i의 범위를 n-1보다 작게 한 이유는 배열을 0으로 모두 초기화 해두었기때문에 n까지 점검할 경우 0-num이 되므로 arr[i+1] - arr[i]가 같다는 조건에서 벗어나게 된다.
        if(tmp != arr[i+1] - arr[i]){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]*2);
    }
    printf("\n");
    for (int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]*(-1));
    }
    return 0;

}
