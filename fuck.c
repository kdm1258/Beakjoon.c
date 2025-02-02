#include <stdio.h>
#include <string.h>

int main(void)
{
   char booklist[5][50] = { "Cygwin과 함께 배우는 C 프로그래밍", "C 99", "A book on C", "C 프로그래밍", "자바 프로그래밍" };
   char search[100];
   int n = 0;
   char  *ptr;

   printf("검색 문장을 입력하세요 : ");
   fgets(search,50,stdin);

   for (int i = 0; i < 5; i++) {
      ptr = strstr(booklist[i], search);

      if (ptr == NULL) {
         n++;
         continue;
      }
      else {
         printf("%s\n", booklist[n]);
         n++;
      }
   }

   return 0;
}
