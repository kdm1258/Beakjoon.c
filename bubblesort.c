#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
void BUBB(int ,int []);
int main(void)
{
	srand(time(NULL));
	sleep(1);

	int arr[5][6] ;
	int temp = 0;

	for (int i = 0 ; i <5 ; i++)
	{
		for (int j = 0 ; j <6 ; j++)
		{
			temp = rand() % 45 + 1 ;
			arr[i][j] = temp;
			for (int k = 0 ; k < j ; k++)
			{
				if (arr[i][k] == arr[i][j])
				{
					j-- ;
					break;
				}
			}

		}
	}

	for ( int i = 0 ; i < 5 ; i++)
	{
		BUBB(6, arr[i]);
		printf("\n%d세트 : %2d", i+1, arr[i][0]);
		for (int j = 1 ; j < 6 ; j++)
		{
			printf(", %2d", arr[i][j]); 
		}
	}
}
void BUBB(int size, int arr[])
{
	int change ;
	for (int j = 0 ; j < size - 1 ; j++)
	{
		for (int i = 1 ; i < size - j ; i++)
		{
			if ( arr[i-1] > arr[i])
			{
				change = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = change;
			}
		}
	}		
}
