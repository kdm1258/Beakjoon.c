#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int c[10];
void sol(int l){
	if(l==m){
		for(int i = 0 ;  i < m ; i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	for(int i = 1 ; i <= n ; i++){
		if(c[i] == 0){
			c[i] = 1;
			arr[l] = i;
			sol(l+1);
			c[i] = 0;
		}
	}
}
int main(void){
	cin>>n>>m;
	sol(0);
}
