#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> E;
int P[1010], n, m, k, C[1010];
bool DfS(){
	for(auto [w,u,v] : E){
		if (
	}
}
int Find(int u){
	return u == P[u] ? u : P[u] = Find(P[u]); 
}
bool Union(int u, int v){
	return Find(u) != Find(v) && (P[P[u]] = P[v], true);
}
int Kruskal(void){
	int ret = 0;
	for(int i = 1 ; i <= n ; i++) P[i] = i;
	for(auto [w, u, v] : E){
		if (Union(u,v))	ret += w;
	}
	return ret;
}
int main(void){
	cin>>n>>m>>k;
	int w = 0;
	for(int i = 1 ; i <= m ; i++){
		int u, int v;
		cin>>u>>v;
		w++;
		E.push_back({w,u,v});
	}
	for(int i = 1 ; i <= n ; i++){
		cout<<Kruskal()<<" ";
	}
}
