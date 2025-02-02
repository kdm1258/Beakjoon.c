#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, w[10101], C[10101], idx = 1;
ll D[10101][2];
vector<int> G[10101];
void DFS(int s){
	C[s] = 1;
	idx++;
	D[idx][0] = max(D[idx-1][0], D[idx-1][1]);
	D[idx][1] = max(D[idx-2][0] + w[s], D[idx-2][1] + w[s]);
	for(auto a : G[s]){
		if (!C[a]){
			DFS(a);
		}
	}
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){ cin>>w[i]; }
	for(int i = 1 ; i < n ; i++){
		int u,v; cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
/*	int Max = 0;
	for(int i = 1 ; i <= n ; i++){
		if(Max < D[i][0]) Max = D[i][0];
		if(Max < D[i][1]) Max = D[i][1];
	}*/
	cout<<max(D[idx][0], D[idx][1]);
}
