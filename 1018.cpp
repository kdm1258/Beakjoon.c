#include <bits/stdc++.h>
using namespace std;
int n,m, Min = INT_MAX;
char board[55][55];
int case1[55][55];
int case2[55][55];
void cmp(){
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			if((i+j)%2==0){
				if(board[i][j] == 'B'){
					case1[i][j] = 0;
					case2[i][j] = 1;
				}
				else{
					case1[i][j] = 1;
					case2[i][j] = 0;
				}
			}
			else{
				if(board[i][j] == 'W'){
					case1[i][j] = 0;
					case2[i][j] = 1;
				}
				else{
					case1[i][j] = 1;
					case2[i][j] = 0;
				}
			}
		}
	}
}
int solve(int x, int y){
	int v1 = 0;
	int v2 = 0;
	for(int i = x+0 ; i< x+8 ; i++){
		for(int j = y+0 ; j <y+8 ; j++){
			v1 += case1[i][j];
			v2 += case2[i][j];
		}
	}
	return min(v1,v2);
}
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i<n ; i++){
		for(int j = 0 ; j<m ; j++){
			cin>>board[i][j];
		}
	}
	cmp();
	for(int i = 0 ; i<=n-8 ; i++){
		for(int j = 0 ; j<=m-8 ; j++){
			int tmp = solve(i,j);
			if(Min>tmp) Min = tmp;
		}
	}

	cout<<Min;
}
