#include <stdio.h>
#include <string.h>
int main(void){
    int A, B, N;
    scanf("%d %d %d", &N, &A, &B);
    if (B > A)
        printf("Bus");
    else if (B < A)
        printf("Subway");
    else printf("Anything");

    return 0;
}
