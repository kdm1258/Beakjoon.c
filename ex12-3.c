#include <stdio.h>
int main(void)
{
	int temp = 0, average = 0;
	int grade[5] = {0};
	
	for (int i = 0 ; i < 5 ; i++)
		scanf("%d",&grade[i]);
	for (int j = 0 ; j < 4 ; j++)
	{
		for (int i = 0 ; i < 4 ; i++)
			if (grade[i] < grade[i+1])
			{
				temp = grade[i];
				grade[i] = grade[i + 1];
				grade[i + 1] = temp;
			}
	}
	for (int i = 0 ; i < 5 ; i++)
	{
		printf("%d등	%d점\n",i+1,grade[i]);
		average += grade[i];
	}
	printf("전체 평균 : %.1f", average / 5.0);
	return 0 ;
}
