#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<int,int>> G1[4040];
vector<pair<int,int>> G2[8080];
int cnt, n, m, C[8080];
ll fox[4040], wolf[8080];
void Dij(ll arr[],vector<pair<int,int>> G[]){
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> Q;
	arr[1] = 0; Q.emplace(make_pair(0,1));
	while(!Q.empty()){	
		auto [c, v] = Q.top(); Q.pop();
		if(C[v]) continue; C[v] = 1;
		for (auto [u, w] : G[v]){
			if(arr[v] + w < arr[u]){
				arr[u] = arr[v] + w;
				Q.emplace(arr[u], u);
			}
		}
	}	
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int a,b,d; cin>>a>>b>>d;
		G1[a].push_back(make_pair(b,2*d));
		G1[b].push_back(make_pair(a,2*d));
		G2[n+a].push_back(make_pair(b,4*d));
		G2[n+b].push_back(make_pair(a,4*d));
		G2[a].push_back(make_pair(n+b,d));
		G2[b].push_back(make_pair(n+a,d));
	}
	for(int i = 1 ; i <= n ; i++) fox[i] = LLONG_MAX;
	for(int i = 1 ; i <= 2*n ; i++) wolf[i] = LLONG_MAX;
	Dij(fox, G1);
	for(int i = 0 ; i <= 2*n ; i++) C[i] = 0;
	Dij(wolf, G2);
	for(int i = 1 ; i <= n ; i++){
		//cout<<fox[i]<<" "<<wolf[i]<<" "<<wolf[n+i]<<"\n";
		if(fox[i] < wolf[i] && fox[i] < wolf[n+i]) cnt++;
	}
	cout<<cnt;
}
