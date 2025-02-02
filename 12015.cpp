#include <bits/stdc++.h>
using namespace std;
int A[1010101];
int N[1010101];
int n;
int cnt;
int bisearch(int l, int r,int k){
	int mid;
	while(l<r){
	mid = (l+r)/2;
		if(N[mid] < k){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	return l;
}
void sol(int k){
	int i = bisearch(0,cnt, k);
	N[i] = k;
	if(i == cnt) cnt++;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>A[i];
		sol(A[i]);
	}
	cout<<cnt;
}
