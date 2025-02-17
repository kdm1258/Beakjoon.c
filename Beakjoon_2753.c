#include <stdio.h>
int main(void){
    int year = 0;

    scanf("%d", &year);

    if (year % 400 == 0){
        printf("%d", 1);
    }
    else if (year % 100 == 0){
        printf("%d", 0);
    }
    else if (year % 4 == 0){
        printf("%d",1);
    }
    else
        printf("%d", 0);
       
}