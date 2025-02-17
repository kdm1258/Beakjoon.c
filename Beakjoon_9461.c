#include <stdio.h>
long long int Padovan[101] = {0,1,1,1,2,2};
int calc_padovan(int k){
    if (k<6) printf("%d\n", Padovan[k]);
    else{
        for (int i = 6 ; i <= k ; i++){
            Padovan[i] = Padovan[i-1] + Padovan[i-5];
        }
        printf("%lld\n", Padovan[k]);
    }
}
int main(void){
    int n = 0;
    int k = 0;

    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &k);
        calc_padovan(k);
    }

}
