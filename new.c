#include <stdio.h>
#include <stdlib.h>

typedef struct Member {
   char name[20];
   int id;
   int age;
   int pay;
} Mb;

int main(int argc, char **argv) {
   FILE *fp;
   int count;
   Mb M = { "", 0, 0, 0 };

   if (argc != 2) {
      fprintf(stderr, "실행 오류\n사용법 : %s out_file\n", argv[0]);
      exit(1);
   }
   if ((fp = fopen(argv[1], "wb")) == NULL) {
      fprintf(stderr, "오류 : %s 파일을 열 수 없습니다.\n", argv[1]);
      exit(1);
   }

   printf("직원 정보를 입력하세요\n");

   count = scanf("%s %d %d %d", M.name, &M.id, &M.age, &M.pay);

   while (count != EOF) {
      fwrite(&M, sizeof(M), 1, fp);
      count = scanf("%s %d %d %d", M.name, &M.id, &M.age, &M.pay);
   }
   fclose(fp);

   return 0;
}

