#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
ll a, b = 1;
vector<pair<ll, ll>> v;
bool compare(const pair<ll,ll> a, const pair<ll,ll> b){
	if (a.second * b.first == b.second * a.first) return a.first > b.first;
	return a.second * b.first > b.second * a.first;
}
ll gcd(ll a, ll b){
	if (b == 0) return a;
	else{
		return gcd(b, a%b);
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		ll x, y; cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), compare);
	int i = 0;
	ll M = 0;
	while(M + v[i].first <= m){
		 M+= v[i].first; a+=v[i].second;
		 i++;
	}
	if(M != m){
	b = v[i].first;
	a *= b;
	a += v[i].second * (m-M);
	}
	ll g = gcd(a,b);
	cout<<a/g<<"/"<<b/g;
}
