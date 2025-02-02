#include <bits/stdc++.h>
using namespace std;
int C[1010],cnt,n,m;
vector<int> G[1010];
void DFS(int v){
	C[v] = 1;
	for (auto i : G[v]) if (!C[i]) DFS(i);
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 1 ; i <= m ; i++){
		int v,e;
		cin>>v>>e;
		G[v].push_back(e);
		G[e].push_back(v);
	}
	for (int i = 1 ; i <= n ; i++){
		if(!C[i]) {
			DFS(i);
			cnt++;
		}
	}
	cout<<cnt;
}
