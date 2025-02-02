#include <bits/stdc++.h>
using namespace std;
int n, m, In[55];
double node[55];
vector<int> G[55];
queue<int> q;
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int v, w; cin>>v>>w;
		G[v].push_back(w);
		In[w]++;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!In[i]) {q.emplace(i); order.push_back(i);}
	}
	node[1] = 100.0;
	while(!q.empty()){
		int s = q.front(); q.pop(); order.push_back(s);
		for(auto a : G[s]) {
			if(!--In[a]) q.emplace(a);
			node[a] += node[s] / G[s].size();
		}
	}
	double max = 0.0;
	for (int i = 1 ; i <= n ; i++){
		if(G[i].size()==0 && node[i] > max) max = node[i];
	}
	cout.precision(7);;
	cout<<fixed<<max;
}
