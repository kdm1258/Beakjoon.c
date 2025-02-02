#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9+7;
ll pow(ll a, ll b, ll c){
	ll res = 1;
	while (b>0){
		if (b%2==1) res = res * a % c;
		b /= 2;
		a = a * a % c;
	}
	return res;
}
int main(void){
	int n, k;
	ll res_n = 1;
	ll fact_k = 1;
	ll fact_nk = 1;
	ll res_k;
	ll res_nk;
	cin>>n>>k;
	for (ll i = 1 ; i <= n ; i++) res_n = res_n * i % INF;
	for (ll i = 1 ; i <= k ; i++) fact_k = fact_k * i % INF;
	for (ll i = 1 ; i <= n-k ; i++) fact_nk = fact_nk * i % INF;
	res_k = pow(fact_k, INF-2, INF);
	res_nk = pow(fact_nk, INF-2, INF);
//	cout<<res_n * res_k % INF * res_nk % INF;
//	cout<<res_n<<'\n'<<res_k<<'\n'<<res_nk<<'\n';
	ll result = ((res_n * res_k) % INF * res_nk) % INF;
	cout<<result;
}
