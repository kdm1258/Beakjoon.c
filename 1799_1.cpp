#include <bits/stdc++.h> 
using namespace std;
int n,Max;
int l[20], r[20];
int board[11][11];
void DFS(int x, int y,int cnt){
	if(x>n){
		if(Max<cnt) Max = cnt;
		return;
	}
	int nextX=x;
	int nextY=y+2;
	if(y==n-1){
		nextX = x+1;
	 	nextY = (n%2 == 1 ? 1 : 2);
	}
	
	else if(y==n){
		nextX = x+1;
	 	nextY = (n%2 == 0 ? 1 : 2);
	}
	if(board[x][y] == 1 && !l[x+y-1] && !r[n+y-x]){
		l[x+y-1] = 1;
		r[n+y-x] = 1;
		DFS(nextX, nextY, cnt+1);
		l[x+y-1] = 0;
		r[n+y-x] = 0;
	}
	DFS(nextX, nextY, cnt);
}
int main(void){
	cin>>n;
	for(int i = 1 ; i<= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin>>board[i][j];
		}
	}  
	DFS(1,1,0);
	int tmp1 = Max;
	Max=0;
	DFS(1,2,0);
	int tmp2 = Max;
	cout<<tmp1+tmp2;
}
