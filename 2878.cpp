#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Pow(ll a, ll b){
	ll c = 1;
	while(b>0){
		if(b%2==1){
			c *= a;
		}
		b /= 2;
		a *= a;
	}
	return c;
}
//const ll MOD = Pow(2,32);
int m , n;
ll k,res,tot,cant, want[101010];
int main(void){
	cin>>m>>n;
	cant = m;
	for(int i = 0 ; i < n ; i++){
		cin>>want[i];
		tot += want[i];
	}
	cant = tot - m;
	sort(want, want + n);
	for(int i = 0 ; i < n ; i++){
		k = min(want[i], cant/(n - i));
		res += k*k;
		cant -= k;
	//	res %= MOD;
	}
	cout<<res;
}	
