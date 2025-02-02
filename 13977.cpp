#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1'000'000'007;
int m, n, k;
ll fact[4040404], inv[4040404];
ll pow(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b % 2 == 1) res = res * a % MOD;
		b/=2;
		a = a * a % MOD;
	}
	return res % MOD;
}
int main (void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fact[0] = 1;
	for(int i = 1 ; i <= 4000000 ; i++){
		fact[i] = fact[i-1] * i % MOD;
	}
	inv[4000000] = pow(fact[4000000], MOD - 2);
	for(int i = 4000000 ; i > 0 ; i--){
		inv[i-1] = inv[i] * i % MOD;
	}
	cin>>m;
	for(int i = 1 ; i <= m ; i++){
		cin>>n>>k;
	//	cout<<fact[n]<<" "<<fact[k]<<" "<<fact[n-k]<<"\n";
		cout<<fact[n] * inv[k] % MOD * inv[n-k] % MOD<<"\n";
	}
}
