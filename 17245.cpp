#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,l,r,mid;
ll sum;
int server[1010][1010];
ll isvalid(int min){
	ll howmany=0;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if (server[i][j] <= min) howmany+=server[i][j];
			else howmany += min;
		}
	}
	return howmany;
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin>>server[i][j];
			sum+=server[i][j];
		}
	}
	l=0;r=*max_element(&server[1][1], &server[n][n]);
	ll half = (sum+1)/2;
	while(l<=r){
		mid = (l+r)/2;
		if(isvalid(mid) < half) l = mid +1;
		else r = mid -1;
	}
	cout<<l;
}
