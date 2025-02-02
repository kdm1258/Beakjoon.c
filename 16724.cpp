#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
char dir[1010][1010];
int c[1010][1010];
int sol(int x, int y){
/*	for(int i = 0 ; i <n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<c[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	*/
	if(c[x][y]==1){
		c[x][y] = 2;
		cnt++;
		return 2;
	}
	else if (c[x][y] == 2){
		return 2;
	}
	c[x][y] = 1;
	if(dir[x][y] == 'D'){
		c[x][y] = sol(x+1,y);
	}
	else if(dir[x][y] == 'U'){
		c[x][y] = sol(x-1,y);
	}
	if(dir[x][y] == 'L'){
		c[x][y] = sol(x,y-1);
	}
	if(dir[x][y] == 'R'){
		c[x][y] = sol(x,y+1);
	}
	return 2;
}
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i <n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>dir[i][j];
		}
	}

	for(int i = 0 ; i <n ; i++){
		for(int j = 0 ; j < m ; j++){
			sol(i,j);
		}
	}

	cout<<cnt;
}
