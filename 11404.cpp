#include <bits/stdc++.h>
using namespace std;
int n, m, C[101], D[101];
vector<pair<int,int>> G[101];
void Dij(int s){
	for (int i = 1 ; i <= n ; i++){D[i] = INT_MAX; C[i] = 0;}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> Q;
	D[s] = 0;
	Q.emplace(0, s);
	while(!Q.empty()){
		auto [p, v] = Q.top(); Q.pop();
		if (C[v]) continue ; else C[v] = 1;
		for(auto [i, w] : G[v]){
			if (D[i] > D[v] + w){
				D[i] = D[v] + w;
				Q.emplace(D[i], i);
			}
		}
	}
	for (int i = 1 ; i <= n ; i++){
		D[i]==INT_MAX?cout<<0<<" ":cout<<D[i]<<" ";
	}
	cout<<"\n";
}
int main(void){
	cin>>n>>m;
	for(int i =1 ; i <= m ; i++){
		int u, v, w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
	}
	for(int i = 1 ; i <= n ; i++){
		Dij(i);
	}

}
