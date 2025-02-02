#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 1'000'000'007;
int t,l;
ll Fac[5050], Inv[5050];
ll Pow(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b%2==1) res = res * a % MOD;
		b/=2; a= a * a % MOD;
	}
	return res;
}
ll Cat(ll a){
	return (Fac[a]*Inv[a/2]%MOD*Inv[a/2]%MOD - Fac[a]*Inv[a/2-1]%MOD*Inv[(a/2+1)]%MOD+MOD)%MOD;
}
int main(void){
	cin>>t;
	Fac[0] = 1;
	for(int i = 1 ; i <= 5000 ; i++){Fac[i] = Fac[i-1] * i % MOD;}
	Inv[5000] = Pow(Fac[5000], MOD-2);
	for(int i = 5000 ; i >= 1 ; i--){Inv[i-1] = Inv[i]*i% MOD;}

	for(int i = 1 ; i <= t ; i++){
		cin>>l;
		if(l%2==0) cout<<Cat(l);
		else cout<<0;
		cout<<"\n";
	}
}	
