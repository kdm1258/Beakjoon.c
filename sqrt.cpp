#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int main(void){
	ll n;
	cin>>n;

	unsigned long long mid = 0;
	ll ret = 0;
	ll l = 0;
	ll r = LLONG_MAX;
	while(l<=r){
		mid = (r+l)/2;
		if (mid*mid >= n) {
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<<ret;
}
