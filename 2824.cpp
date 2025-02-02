#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N,M;
vector<ll> A;
vector<ll> B;
ll gcd(ll a, ll b){
	if (a<b) {ll tmp = a; a = b; b = tmp;}
	if(b==0) return a;
	else return gcd(b, a%b);
}
int main(void){
	cin>>N;
	for(int i = 1 ; i <= N ; i++){
		ll tmp; cin>>tmp;
		A.push_back(tmp);
	}
	cin>>M;
	for(int i = 1 ; i<= M ; i++){
		ll tmp; cin>>tmp;
		B.push_back(tmp);
	}
	ll ans = 1;
	bool flag = false;
	for(int i = 0 ; i < N ; i++){
		for(int j  = 0 ; j < M ; j++){
			ll tmp ;
			tmp = gcd(A[i], B[j]);
			ans *= tmp;
			A[i] /= tmp;
			B[j] /= tmp;
			if(ans>=1000000000LL){ans %= 1000000000LL; flag = true;}
		}
	}	
	if(flag)printf("%09lld",ans);
	else cout<<ans;
}
