#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> check;
vector<ll> pri;
void seive(int n){
	check.resize(n+1, false);
	for (int i = 2 ; i <= n ; i++){
		if (!check[i]){
			pri.push_back(i);
			for (int j = i*i ; j <= n ; j+=i){
				check[j] = true;
			}
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, b;
	cin>>a>>b;
	seive(100000000);
	string com;
	string rev;
	for (int i = 0 ; pri[i] <= b && i<pri.size() ; i++){
		int k = pri[i];
		if(a<=k){
			com = to_string(k);
			string frn = com;
			reverse(com.begin(), com.end());
			rev = com;
			if (rev == frn) cout<<com<<'\n';
		}
	}
	cout<<-1;
}
