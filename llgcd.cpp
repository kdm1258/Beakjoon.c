#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> check;
vector<ll> pri;
void pri(ll n){
	for (ll i = 2 ; i*i <= n ; i++){
		if (!check[i]) pri.push_back(i);
		for (int j = i*i ; j <=n ; j+=i)check[j] = 1;
	}
}
