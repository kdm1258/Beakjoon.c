#include <stdio.h>
void diff_array(int arr[], int first, int diff, int size);
int main(void)
{
	int arr[10];
	diff_array(arr,2,3,10);
	for (int i = 0 ; i < 10 ; i++)
		printf("%d  ", arr[i]);
}

void diff_array(int arr[], int first, int diff, int size)
{
	for (int i = 0 ; i < size ; i++)
	{
		arr[i] = first;
		first += diff;
	}
}
