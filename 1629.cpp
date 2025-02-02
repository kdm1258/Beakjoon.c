#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Pow(ll a, ll b, ll c){
	ll res = 0;
	if (b==0) return 1;
	else res = Pow(a, b/2 , c);
	if (b%2!=0) return a * res % c * res % c;
	else return res * res %c;
}
int main(void){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<Pow(a,b,c);
}
