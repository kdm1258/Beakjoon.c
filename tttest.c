#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

struct linked_list {

	char d;

	struct linked_list *next;

};

typedef struct linked_list ELEMENT;

typedef ELEMENT *LINK;

//LINK string_to_list(char s[]) {

//	LINK head;

//	if (s[0] == '\0')

//	return NULL;
//else {

//	head = malloc(sizeof(ELEMENT));

//	head -> d = s[0];

//	head -> next = string_to_list(s + 1);

//	return head;

//}

//}
LINK string_to_list(char s[]){
	
	int i = 1;
	LINK head = (LINK)malloc(sizeof(ELEMENT));
	if (s[0] == '\0'){
		return NULL;
	}
	else{
	head -> d = s[0];
	head -> next = NULL;
	LINK tmp = (LINK)malloc(sizeof(ELEMENT));
	tmp = head;
	while(s[i] != '\0'){
		LINK node = (LINK)malloc(sizeof(ELEMENT));
		node -> d = s[i];
		node -> next = NULL;
		i++;

		tmp -> next = node;
		tmp = tmp ->next;
	}
	return head;
	}
}

void print_list(LINK head) {

	if (head == NULL)

	printf("NULL \n");

	else {

	printf("%c --> ", head -> d);

	print_list(head -> next);

	}	

}

int main(void) {

	char input[N];
	LINK h;
	while(1){

		printf("문자열 입력: ");
		scanf("%s", input);
		if (strcmp(input,"exit") != 0){
			h = string_to_list(input);

			printf("변환 리스트 결과 : \n");

			print_list(h);
		}
		else{
			printf("BYE......\n");
			return 0;
		}
	}
}
