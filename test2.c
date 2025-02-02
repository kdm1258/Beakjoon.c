#include <stdio.h>
#include <stdlib.h>
struct info{
    char name[20];
    int id, age, salary;
};

int main(void){

    FILE *fp;
    struct info em = {"",0,0,0};
   if((fp = fopen("employee.bin","wb")) == NULL){
        fprintf(stderr,"오류 : 파일을 열 수 없습니다\n");
        exit(1);
    }
    while(scanf("%s %d %d %d\n",em.name, &em.id, &em.age, &em.salary) != EOF){
  
        fwrite(&em, sizeof(em), 1, fp);
    }
    fclose(fp);

    return 0;
}

