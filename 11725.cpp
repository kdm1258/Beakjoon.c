#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[101010];
int P[101010];
int c[101010];
void DFS(int s,int p){
	if(c[s]==1) return;
	P[s] = p;
	c[s] = 1;
	for (auto a : v[s]){
		DFS(a,s);
	}
}
int main(void){

	cin>>n;
	for(int i = 1 ; i < n ; i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(1,1);
	for(int i = 2 ; i<= n ; i++) cout<<P[i]<<"\n";
}
