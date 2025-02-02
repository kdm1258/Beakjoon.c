#include <bits/stdc++.h>
using namespace std;
int n, m, v, C[10101]; 
vector<int> G[10101];
void DFS(int s){
	C[s] = 1;
	cout<<s<<" ";
	for(auto a : G[s]){
		if(C[a] != 1) DFS(a);
	}	
}
void BFS(int s){
	queue<int> q;
	C[s] = 1; q.emplace(s);
	while(!q.empty()){
		s = q.front(); q.pop();
		cout<<s<<" ";
		for(auto a : G[s]){
			if (C[a] != 1) {
				C[a] = 1;
				q.emplace(a);
			}
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cin>>n>>m>>v;
	for(int i = 1 ; i <= m ; i++){
		int s, e; cin>>s>>e;
		G[s].push_back(e);
		G[e].push_back(s);
	}
	for(int i = 1 ; i <= n ; i++)sort(G[i].begin(), G[i].end());
	DFS(v); 
	cout<<"\n"; 
	for(int i = 0 ; i <= n ; i++) C[i] = 0;
	BFS(v);
}
