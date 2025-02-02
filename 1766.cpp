#include <bits/stdc++.h>
using namespace std;
int n, m, Indgree[32323];
priority_queue<int, vector<int>, greater<>> q;
vector<int> G[32323];
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		Indgree[v] += 1;
	}
	for(int i = 1 ; i<= n ; i++){if(!Indgree[i]) q.emplace(i);}
	while(!q.empty()){
		int v = q.top(); q.pop();
		cout<<v<<" ";
		for (auto a : G[v]){
			if(!(--Indgree[a])) q.emplace(a);
		}
	}
}
