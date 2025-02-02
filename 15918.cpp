#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int cnt;
int arr[25];
void sol(int k){
	if(k==0){ 
		cnt++;
		return;
	}
	for(int i = 1 ; i+k+1<= 2*n ; i++){
		if(k == y-x-1) {sol(k-1);return;}
		if(arr[i] == 0 && arr[i+k+1] == 0){
				//for(int i = 1 ; i<= 2*n ; i++) cout<<arr[i]<<" "; cout<<"\n";
				arr[i] = k; arr[i+k+1] = k;
				sol(k-1);
				arr[i]=0; arr[i+k+1] = 0;
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>x>>y;
	arr[x] = y-x-1;
	arr[y] = y-x-1;
	sol(n);
	cout<<cnt;
}
