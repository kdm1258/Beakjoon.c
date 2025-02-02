#include <bits/stdc++.h>
using namespace std;
int n ,m,s,f, C[1010], D[1010], Parent[1010] ;
vector<pair<int, int>> G[1010];
void Dij(void){
	for(int i = 1 ; i <= n ; i++){ D[i] = INT_MAX; Parent[i] = -1;}
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> Q;
	D[s] = 0;
	Q.emplace(0,s);
	while(!Q.empty()){
		auto [p, v] = Q.top(); Q.pop();
		if(C[v]) continue; else C[v] = 1;

		for(auto [i, w] : G[v]){
			if (D[i] > D[v] + w){
				D[i] = D[v] + w;
				Parent[i] = v;			//직전의 부모노드 기록
				Q.emplace(D[i], i);
			}
		}
	}
}
vector<int> getPath(int end){
	vector<int> path;
	for(int v = end ; v != -1 ; v = Parent[v]){path.emplace_back(v);}
	reverse(path.begin(), path.end());
	return path;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 1; i <= m ; i++){
		int u, v, w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
	}
	cin>>s>>f;
	Dij();
	cout<<D[f]<<"\n";
	vector<int> path = getPath(f);
	cout<<path.size()<<"\n";
	for(auto i : path) cout<<i<<" ";
}
