#include <bits/stdc++.h>
using namespace std;
int n, m, s ,C[101], D[101], P[101];
vector<pair<int,int>> G[101];
vector<vector<int>> Path;
vector<int> getPath(int end);
void Dij(int s){
	for (int i= 1; i <= n ; i++){
		D[i] = INT_MAX; C[i] = 0; P[i] = -1;
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> Q;
	D[s] = 0;
	Q.emplace(0,s);

	while(!Q.empty()){
		auto [c,v] = Q.top(); Q.pop();
		if (C[v]) continue; else C[v]=1;
		for(auto [i, w] : G[v]){
			if (D[i] > D[v] + w){
				D[i] = D[v] + w;
				P[i] = v;
				Q.emplace(D[i], i);	
			}
		}
	}
	for (int i = 1 ; i<= n ; i++){
		D[i]==INT_MAX?cout<<0<<" ":cout<<D[i]<<" ";
		Path.emplace_back(getPath(i));
	}
	cout<<"\n";
}
vector<int> getPath(int end){
	vector<int> path;
	for (int v = end ; v != -1 ; v = P[v]){
		path.emplace_back(v);
	}
	reverse(path.begin(), path.end());
	return path;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 1 ; i<=m ; i++){
		int u, v, w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
	}
	for (int i = 1 ; i<=n ; i++){
		Dij(i);
	}
	for(auto i : Path){
		if(i.size()==1){
			cout<<0<<"\n";
			continue;
		}
		else{
			cout<<i.size()<<" ";
			for(auto j : i){
				cout<<j<<" ";
			}
		}
		cout<<"\n";
	}
}
