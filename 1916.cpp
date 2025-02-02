#include <bits/stdc++.h>
using namespace std;
int C[1010], s, e, n, m, D[1010];
vector<pair<int,int>> G[1010];
void Dij(void){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	for(int i = 1 ; i <= n ; i++){D[i] = INT_MAX;}
	D[s] = 0;
	pq.emplace(0, s);
	while(!pq.empty()){
		auto [i, v] = pq.top(); pq.pop();
		if(C[v]) continue;
		else C[v] = 1;
	 	for(auto [p, q] : G[v]){
			if(D[p] > D[v]+q){
				D[p] = D[v] + q;
				pq.emplace(D[p],p);
			}
		}	
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w; cin>>u>>v>>w;
		G[u].emplace_back(v,w);
	}
	cin>>s>>e;
	Dij();
	cout<<D[e];
}
