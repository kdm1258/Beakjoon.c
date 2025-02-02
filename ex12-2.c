#include <stdio.h>
void set_to_zero(int a[], int size);
int main(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	set_to_zero(arr,10);
	for (int i = 0 ; i<=9; i++)
		printf("%d", arr[i]);
	return 0;
}

void set_to_zero(int a[], int size)
{
	for (int i = 0 ; i < size ; i++)
		a[i] = 0;
}
