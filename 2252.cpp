#include <bits/stdc++.h>
using namespace std;
int n, m, C[32323];
vector<int> G[101010];
vector<int> ans;
void DFS(int v){
	C[v] = 1;
	for (auto i : G[v]) if(!C[i]) DFS(i);
	ans.push_back(v);
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int e,w;
		cin>>e>>w;
		G[e].push_back(w);
	}
	for(int i = 1 ; i <= n ; i++){
		if(!C[i]) DFS(i);
	}
	reverse(ans.begin(), ans.end());
	for(auto i : ans) cout<<i<<" ";
}
