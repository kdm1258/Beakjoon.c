#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> ballonTime(1010101);
int n, m;
int min_t=999999999;
ll howmany(ll t){
	ll cnt = 0;
	for(int i = 0 ; i < n ; i++){
		cnt += t / ballonTime[i];
	}
	return cnt;
}
ll bisearch(ll m){
	ll l = 0;
	ll r = min_t*m;
	ll result = 0;
	while(l <= r){
		ll mid = (l+r)/2;
		if (howmany(mid) >= m) {
			result = mid;
			r = mid -1;
		}
		else if (howmany(mid) < m) l = mid +1;
	}
	return result;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 0 ; i < n ; i++){
		cin>>ballonTime[i];
		min_t = min(min_t, ballonTime[i]);
	}
	cout<<bisearch(m);
}
