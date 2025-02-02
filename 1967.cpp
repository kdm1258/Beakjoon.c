#include <bits/stdc++.h>
using namespace std;
int n, M, Index;
int c[10101], dist[10101];
vector<pair<int, int>> tree[10101];
void DFS(int s){
	c[s] = 1;
	for(auto a : tree[s]){
		if(!c[a.first]){
			dist[a.first] = dist[s] + a.second;
			DFS(a.first);
		}
	}
}
int main(void){
	cin>>n;
	for(int i = 1 ; i < n ; i++){
		int tmp; cin>>tmp;
		int u; cin>>u;
		int v; cin>>v;
		tree[tmp].push_back(make_pair(u,v));
		tree[u].push_back(make_pair(tmp,v));
	}
	DFS(1);
	for(int i = 1 ; i<= n ; i++){
		if (M<dist[i]){ M = dist[i]; Index = i;}
		dist[i] = 0; c[i] = 0;
	}

	M = 0;
	DFS(Index);
	for(int i = 1 ; i<= n ; i++){
		if (M<dist[i]){ M = dist[i];}
	}
	cout<<M;
}
