#include <bits/stdc++.h>
using namespace std;
int flag = 0;
int board[10][10];
int row[10][10];
int col[10][10];
int box[10][10];
void sol(int x, int y){
	int I = x*9+y;
	if(x==8 && y == 9){
		flag = 1;
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				cout<<board[i][j];
			}
			cout<<"\n";
		}
		return;
	}
	x =I/9;
	y =I%9;
	if(board[x][y] != 0){
		sol(x,y+1);
		return;
	}
	for(int i = 1 ; i <= 9 ; i++){
		if(flag==0 && row[x][i-1] == 0 && col[y][i-1] == 0 && box[(x/3)*3+(y/3)][i-1] == 0){
	//		cout<<i<<" "<<x<<" "<<y<<"\n";
				row[x][i-1] = 1;
	 		  	col[y][i-1] = 1;
				box[(x/3)*3+(y/3)][i-1] = 1;
				board[x][y] = i;
		
				sol(x, y+1);
				
				row[x][i-1] = 0;
			   	col[y][i-1] = 0; 
				box[(x/3)*3+(y/3)][i-1] = 0;
				board[x][y] = 0;
			}
		}
}
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for(int i =0 ; i < 9 ; i++){
			int t;
			cin>>t;
		for(int j = 8 ; j >= 0 ; j--){
			int tmp = t%10;
			t/=10;
			board[i][j] = tmp;
			row[i][tmp-1] = 1;
			col[j][tmp-1] = 1;
			box[(i/3)*3+(j/3)][tmp-1] = 1;
		}
	}
	sol(0,0);
}
