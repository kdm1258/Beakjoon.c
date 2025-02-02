#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int arr[10];
int c[10];
void DFS(int cnt){
	if(cnt == m){
		for(int i = 0 ; i < m ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 0 ; i < n ; i++){
		if(c[i]==0){
			c[i] = 1;
			arr[cnt] = v[i];
			DFS(cnt+1);
			c[i]=0;
		}
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		int tmp; cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	DFS(0);
}
