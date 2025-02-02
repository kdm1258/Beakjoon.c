#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, C[1010];
vector<int> G[1010];
void DFS(int s){
	C[s] = 1;
	for(auto a : G[s]){
		if(C[a] != 1) DFS(a);
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int a,b; cin>>a>>b; G[a].push_back(b); G[b].push_back(a);
	}
	for(int i = 1 ; i <= n ; i++){
		if(C[i] != 1){DFS(i); cnt++;}
	}
	cout<<cnt;
}
