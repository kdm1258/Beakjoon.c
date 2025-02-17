#include <stdio.h>
int func(int, int [], int[]);

int main(void)
{
	int n = 0;
	
	scanf("%d",&n);

	int stairs[100000] ={0};
	int arr[100000] = {0};
	for (int i = 1 ; i <= n ; i++){
	    scanf("%d",&arr[i]);
	}
	stairs[1] = arr[1];
	stairs[2] = arr[1] +arr[2];
	for (int i =3 ; i <= n ; i++)
	{
    	stairs[i] = func(i, arr, stairs);
	}
	printf("%d", stairs[n]);
}

int func(int n, int arr[], int stairs[]){
        return ((arr[n-1] + arr[n] + stairs[n-3]) > (arr[n] + stairs[n-2])) ? arr[n-1] + arr[n] + stairs[n-3] : (arr[n] + stairs[n-2]);
    }
    
