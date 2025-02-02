#include <bits/stdc++.h>
using namespace std;
int n, k, cnt ,path;
int d[101010];
int w[101010];
int c[101010];
vector<int> tree[101010];
void BFS(int s){
	queue<int> q;
	q.push(s);
	d[s] = 0;
	w[s] = 1;
	while(!q.empty()){
		int u = q.front(); 
		q.pop();
		for(auto a : tree[u]){
			if(!c[a]){ 
				c[a] = 1;
				q.push(a);
				d[a] = d[u]+1;
				w[a] = w[u];
			}
			else if(d[a] == d[u]+1){
				w[a] += w[u];
			}
		}
	}

}
int main(void){
	cin>>n>>k;
	if(n==k){ cout<<0<<"\n"<<1; return 0;}
	tree[0].push_back(1);
	tree[100000].push_back(99999);
	for(int i = 1 ; i < 100000 ; i++){
		tree[i].push_back(i+1);	
		tree[i].push_back(i-1);
		if(i*2<=100000)tree[i].push_back(i*2);	
	}
	BFS(n);
	cout<<d[k]<<"\n"<<w[k];
}

