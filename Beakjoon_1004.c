#include <stdio.h>
#include <math.h>
int main(void){
    int arr[250000];
    int x1, y1, x2, y2, cx, cy, r, T, n, cnt = 0;
    scanf("%d", &T);
    for (int i = 0 ; i < T ; i++){
        cnt = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);

        for (int j = 0; j < n ; j++){
            scanf("%d %d %d",&cx, &cy, &r);
            if ((pow((cx - x1), 2) + pow((cy - y1), 2) < pow(r, 2)) && (pow((cx - x2), 2) + pow((cy - y2), 2) > pow(r, 2))){
                cnt++;
            }
            if ((pow((cx - x2), 2) + pow((cy - y2), 2) < pow(r, 2)) && (pow((cx - x1), 2) + pow((cy - y1), 2) > pow(r, 2))){
                cnt++;
            }
        }
        arr[i] = cnt;
    }
    for (int i = 0; i < T ; i++)
        printf("%d\n",arr[i]);
}
