#include <bits/stdc++.h>
using namespace std;
int n, m ,C[51];
double a[51];
vector<int> G[101];
int main(void){
	cin>>n>>m;
	for (int i = 1 ; i<= m ; i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	a[1] = 100.0;
	double max = 0.0;
	for (int i = 1 ; i<= n ; i++){
		for (auto j : G[i]){
			a[j] += (double)a[i]/G[i].size();
		}	
	}
	for (int i = 1 ; i<= n ; i++){
		if (G[i].size() == 0 && max<a[i]) max = a[i];
	}
	cout.precision(7);
	cout<<fixed<<max;
}
