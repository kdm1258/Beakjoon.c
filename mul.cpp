#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll a, ll b, ll c){
	ll half = 0;
	if (b==0) return 1;
	half = f(a, b/2, c);
	if !(b%2) return half * half % c;
	else return a * half % c * half % c;
}
int main(void){
	int a,b,c;
	ll r = 1;
	cin>>a>>b>>c;
	
	cout<<f(a,b,c);
}
