#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> G;  //weight, node1, node2
int P[2020], n, m, s;
int Find(int v){
	 return v == P[v] ? v : P[v] = Find(P[v]);
}
bool Union(int u, int v){
	return Find(u) != Find(v) && (P[P[u]] = P[v], true);
}
int Kruskal(){
	int ret = 0;
	for(int i = 1; i <= n ; i++) P[i] = i;
	sort(G.begin(), G.end());
	for(auto [w,u,v] : G){
		if(Union(u,v)){
			ret += w;
		}
	}
	return ret;
}
int main(void){
	cin>>n>>m>>s;
	for(int i = 1 ; i <= m ; i++){
		int  u,v,w; cin>>u>>v>>w;
		G.push_back({w, u, v});
	}for(int i = 1 ; i <= n ; i++){int tmp; cin>>tmp;}
	cout<<Kruskal();
}
