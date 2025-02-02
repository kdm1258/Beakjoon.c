#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ll> weight;
	ll sum = 1;
	int n = 0;
	int tmp = 0;
	cin>>n;
	for (int i = 0 ; i < n ; i++){
		cin>>tmp;
		weight.push_back(tmp);
	}
	sort(weight.begin(),weight.end());
	for (int i = 0 ; i< n ; i++){
			if (sum < weight[i]) break;
			sum += weight[i];
	}
	
	cout<<sum;
}
