#include <stdio.h>
int main(void)
{
    int n,k;
    long a[100];
    long b[1000000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &a[i]);
        scanf("%ld", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        k = a[i]%10;
        for (int j = 1 ; j < b[i] ; j++){
            k = (k * a[i])%10;
        }
        if (k != 0)
            printf("%d\n",k);
    	else 
	    printf("%d\n",10);
    }
