#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> G[20202];
int V, E, Check[20202], Di[20202], start;
void Dij(){
	for (int i = 1 ; i <= V ; i++) Di[i] = INT_MAX;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	Di[start] = 0;
	pq.emplace(0,start);//pq에 들어가는 값은 (D[i]현재까지 가중치, i 인덱스)
	while(!pq.empty()){
		auto [c,v] = pq.top(); 
		pq.pop();

		if(Check[v]) continue;
		Check[v] = 1;
		for(auto [i,w] : G[v]){
			if(Di[i] > Di[v] + w){		
				Di[i] = Di[v] + w;
				pq.emplace(Di[i],i);
			}
		}
	}	
}
int main(void){
	cin>>V>>E>>start;
	for(int i = 0 ; i < E ; i++){
		int u, v, w;
		cin>>u>>v>>w;
		G[u].emplace_back(v, w);
	}
	Dij();
	for(int i = 1 ; i <= V ; i++){
		if(Di[i] == INT_MAX) cout<<"INF"<<"\n";
		else cout<<Di[i]<<"\n";
	}
}
