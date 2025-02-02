#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll add(ll a, ll b , ll c){
	return (a+b)%c;
}
ll mul(ll a, ll b, ll c){
	ll res = 0;
	/*
	res = add(a,a,c);
	for (int i = 2; i < b ; i++){
		res = add(res,a,c);
	}*/
	while (b>0){
		if(b%2 == 1) res = add(res,a,c);
		b/=2; a = add(a,a,c);
	}
	return res;
}
ll pow(ll a, ll b, ll c){
	ll res = 1;
	while(b>0){
		if (b % 2 == 1) res = mul(res, a, c);
		b /= 2; a = mul(a, a, c);
	}return res;
}
int main(void){
	ll a; ll b; ll c;
	cin>>a>>b>>c;
	cout<<pow(a,b,c);
}
