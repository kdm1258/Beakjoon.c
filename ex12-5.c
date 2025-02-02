#include <stdio.h>
void grade_array(int score[], char grade[], int size)
{
	for (int i = 0; i < size ; i++)
	{
		switch (score[i]/10)
		{
			case 10:
			case 9:
				grade[i] = 'A';
				break ;
			case 8:
				grade[i] = 'B';
				break;
			case 7:
				grade[i] = 'C';
				break ;
			case 6:
				grade[i] = 'D';
				break ;
			default:
				grade[i] = 'F';
		}
	}
}
int main(void)
{
	int score[10] = {100,90,80,70,60,50,74,84,94,11};
	char grade[10];
	grade_array(score , grade, 10);
	for (int i = 0; i < 10 ; i++)
		printf("%c", grade[i]);
}
