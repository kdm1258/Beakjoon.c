#include <bits/stdc++.h>
using namespace std;
int n , k, cnt;
vector<int> money;
int main(void){
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i++){
		int tmp; cin>>tmp;
		money.push_back(tmp);
	}
	for(int i = n-1 ; i >= 0 ; i--){
		int p;
		p = k / money[i];
		k %= money[i];
		cnt += p;
	}
	cout<<cnt;
}

