#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int arr[10];
void sol(int cnt){
	if(cnt==m){
		for(int i = 0 ; i < m ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 0 ; i < n ; i++){
			arr[cnt] = v[i];
			sol(cnt+1);
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		int tmp; cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	sol(0);
}
