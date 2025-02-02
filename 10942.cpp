#include <bits/stdc++.h>
using namespace std;
int n,m,s,e;
int arr[2020];
int odd[2020][1010];
int even[2020][1010];
void sol(void){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= i-1 && j <= n-i ; j++){
			if(arr[i-j] == arr[i+j]){
				odd[i][j] = 1;
			}
			else{
				break;
			}
		}
	}
	for(int i = 1 ; i < n ; i++){
		for(int j = 1 ; j <= i && j <= n-i ; j++){
			if(arr[i-j+1] == arr[i+j]){
				even[i][j] = 1;
			}
			else{
				break;
			}
	}
		
	}
}	
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1 ; i<= n ; i++){
		cin>>arr[i];
	}
	cin>>m;
	sol();
	for(int i = 1 ; i <=m ; i++){
		cin>>s>>e;
		int mid = (s+e)/2;
		if(mid*2 == s+e){
			cout<<odd[mid][e-mid]<<"\n";
		}
		else{
			cout<<even[(s+e)/2][e-mid]<<"\n";
		}
	}
}
