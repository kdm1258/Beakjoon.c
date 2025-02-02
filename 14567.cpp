#include <bits/stdc++.h>
using namespace std;
int n, m, indegree[1010], dist[1010];
vector<int> G[1010];
queue<int> Q;
void BFS(){
	while(!Q.empty()){
		int v = Q.front(); Q.pop(); 
		for(auto i : G[v]){
			indegree[i]--;
			if(indegree[i] ==0){
			Q.push(i);
			dist[i] = max(dist[v] + 1, dist[i]);			
			}
		}
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int a, b;
		cin>>a>>b;
		G[a].push_back(b);
		indegree[b]++;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(indegree[i] == 0) {
			Q.push(i);
			dist[i] = 1;
		}
	}
	BFS();
	for(int i=1 ; i<=n ;i++)cout<<dist[i]<<" ";
}
