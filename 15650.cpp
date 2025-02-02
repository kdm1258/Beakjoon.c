#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
void DFS(int s, int cnt){
	if(cnt == m){
		for(int i = 0 ; i < m ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = s ; i <=n ; i++){
		arr[cnt] = i;
		DFS(i+1, cnt+1);
	}
}
int main(void){
	cin>>n>>m;
	DFS(1,0);
}
