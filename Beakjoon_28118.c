#include <stdio.h>
int n = 0;
int c[41] = {0};
int arr[41][41] = {0};
void dfs(int v);
int main(void){
	int m = 0;
    int cnt = 0;
	scanf("%d %d", &n, &m);

	//배열 초기화
	for(int i = 1 ; i <= m ; i++){
		int tmpTup = 0;
		int tmpClm = 0;
		scanf("%d %d", &tmpTup, &tmpClm);
		arr[tmpTup][tmpClm] = 1;
		arr[tmpClm][tmpTup] = 1;
	}

    //solve
    for (int i = 1; i <= n ; i++){
        if (c[i]!=1) dfs(i), cnt++;
    }
    printf("%d", --cnt);
}
void dfs(int v){
    c[v] = 1;
    for (int i = 1 ; i <= n ; i++){
        if ((!c[i])&&(arr[v][i])) dfs(i);
    }
}
