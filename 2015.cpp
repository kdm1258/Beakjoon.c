#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k , S[202020],  A[202020];
map<ll, ll> m;
int main(void){
	cin>>n>>k;
	ll cnt = 0;
	m[0]=1;
	for(int i=1 ; i <= n ; i++){
		cin>>A[i];
		S[i] = S[i-1] + A[i];
	}
	for (int i = 1 ; i <= n ; i++){
		cnt += m[S[i] - k];
		m[S[i]]++;
	}
	cout<<cnt;
}
