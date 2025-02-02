#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}	
ll lcm(int a, int b){
	return (ll)a / gcd(a,b) * b;
}
int main(void){
	vector<ll> arr1;
	vector<ll> arr2;
	ll a, b ,L;
	cin>>a>>b>>L;
	bool flag = false;
	for(ll i = 1 ; i <= sqrt(L) ; i++){
		if(!(L%i)) {
		arr1.push_back(i);
		arr2.push_back(L/i);
		}
	}
	ll k = lcm(max(a,b),min(a,b)) ;
	for (ll c : arr1){
		if ((double)c/gcd(max(k,c),min(k,c)) ==(double)L/k) {cout<<c;
		flag = true; break;}
	}reverse(arr2.begin(), arr2.end());
	if(!flag){
	for (ll c : arr2){
		if ((double)c/gcd(max(k,c),min(k,c)) ==(double)L/k) {cout<<c;
		flag = true; break;}
	}}
	if(!flag) cout<<-1;
}
