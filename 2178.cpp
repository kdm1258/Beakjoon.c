#include <bits/stdc++.h>
using namespace std;
int C[10101], Maze[101][101], dist[10101];
int n,m;
vector<int> G[10101];
void BFS(int v){
	queue<int> Q;
	C[v] = 1; dist[v] =1;
	Q.push(v);
	while(!Q.empty()){
		v = Q.front(); Q.pop();
		for(auto i : G[v]){
			if(!C[i]){
			   	Q.push(i);
				C[i] = 1;
				dist[i] = dist[v]+1;
			}
		}
	}
}
void mazeTograph(void){
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= m ; j++){
			char c; cin>>c;
			Maze[i][j] = c -'0';
		}
	}
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= m ; j++){
			if(Maze[i][j] == 1){
				if(Maze[i+1][j] == 1) G[(i-1)*m+j].push_back(i*m+j);
				if(Maze[i][j+1] == 1) G[(i-1)*m+j].push_back((i-1)*m+j+1);
				if(Maze[i-1][j] == 1) G[(i-1)*m+j].push_back((i-2)*m+j);
				if(Maze[i][j-1] == 1) G[(i-1)*m+j].push_back((i-1)*m+j-1);
			}
		}
	}

}	
int main(void){
	cin>>n>>m;
	mazeTograph();
	BFS(1);
	cout<<dist[n*m];
}
