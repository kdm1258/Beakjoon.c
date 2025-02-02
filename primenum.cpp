#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 8080808;
vector<bool> C(MAXN+1, 0);
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	ll prime = 0;
	cin>>k;
	for (int i = 2 ; i <= MAXN ; i++){
		if (C[i] == 1) continue;
		prime++;
		if (prime == k) cout<<i;
		for (ll j = (ll)i*i ; j <= MAXN ; j += i){
			C[j] = 1;
		}
	}

}
