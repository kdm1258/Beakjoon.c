#include <bits/stdc++.h>
using namespace std;
int n,cnt,Max;
int board[11][11];
void DFS(int x, int y){
	if(x>n || y > n){ 
		if(Max<cnt) Max = cnt;
		return;}
		if(board[x][y]==1){
			cnt++;
			int i = 0;
			while(x+i<=n && y+i <= n){
				if(board[x+i][y+i] == 1) board[x+i][y+i] = -1;
				i++;
			}
			i = 0;
			while(x+i<=n && y-i >= 1){
				if(board[x+i][y-i] == 1) board[x+i][y-i] = -1;
				i++;
			}
			if(y==n) DFS(x+1,1);
			else DFS(x,y+1);
		
			i = 0;
			while(x+i<=n && y+i <= n){
				if(board[x+i][y+i] == -1) board[x+i][y+i] = 1;
				i++;
			}
			i = 0;
			while(x+i<=n && y-i >= 1){
				if(board[x+i][y-i] == -1) board[x+i][y-i] = 1;
				i++;
			}
			cnt--;
		}
		if(y==n) DFS(x+1,1);
		else DFS(x,y+1);
}
int main(void){
	cin>>n;
	for(int i = 1 ; i<= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin>>board[i][j];
		}
	}
	DFS(1,1);
	cout<<Max;
}
