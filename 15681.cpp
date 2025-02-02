#include <bits/stdc++.h>
using namespace std;
int ans[101010];
int n, r, q;
vector<int> G[101010];
int DFS(int v, int parent){
	ans[v]=1;
	for (auto i : G[v]) if(i != parent) ans[v] += DFS(i, v);
	return ans[v];
}
int main(void){
	cin>>n>>r>>q;
	for (int i = 1 ; i<n ; i++){
		int u,v; cin>>u>>v; G[u].push_back(v); G[v].push_back(u);
	}	
	DFS(r,-1);
	 for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << ans[tmp] << "\n"; 
    }
}
