#include <stdio.h>
#include <string.h>
void add(int list[20],int x){
    list[x-1] = 1;
}
void my_remove(int list[20], int x){
    list[x-1] = 0;
}
void check(int list[20], int x){
    printf("%d\n",list[x-1]);
}
void toggle(int list[20], int x){
    if(list[x-1] ==0){
        list[x-1] =1;
    }
    else if(list[x-1] ==1){
        list[x-1] =0;
    }
}
void all(int list[20]){
    for (int i = 0 ; i <20 ; i++){
        list[i]=1;
    }
}
void empty(int list[20]){
    for (int i = 0 ; i <20 ; i++){
        list[i] = 0;
    }
}
int main(void){
    int list[20] = {0};
    int n = 0;
    int tmp = 0;   
    char string[100];
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++){
        scanf("%s", string);
        scanf("%d", &tmp);
        if (strcmp(string, "add")==0){
            add(list, tmp);
        }
        else if (strcmp(string, "remove")==0){
            my_remove(list, tmp);
        }
        else if (strcmp(string, "check")==0){
            check(list, tmp);
        }
        else if (strcmp(string, "toggle")==0){
            toggle(list, tmp);
        }
        else if (strcmp(string, "all")==0){
            all(list);
        }
        else if (strcmp(string, "empty")==0){
            empty(list);
        }
        
    }
}
