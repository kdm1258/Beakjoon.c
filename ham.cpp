#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p = 0;
ll h[51];
ll ham(int n, ll x){
	if (n==0){
		p++;
		if(--x ==0) return p;
	}
	else {
		if(--x==0) return p;
		ham(n-1,x);
		if(--x==0) return p;
		p++;
		if(--x==0) return p;
		ham(n-1,x);
		if(--x==0) return p;
	}
	return p;
}
int main(void){
	int n,x;
	cin>>n>>x;
	cout<<ham(n,x);
}
