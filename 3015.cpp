#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int n, cnt;
ll seq[505050];
ll ans=0;
stack<pair<ll,int>> stk;
void sol(void){
	for(int i = n-1 ; i>= 0 ; i--){
		int del = 0;
		int cnt = 1;
		ll top = 0;
		while(!stk.empty() && seq[i] >= stk.top().first){
			del += stk.top().second;
			if(stk.top().first == seq[i]) cnt += stk.top().second; 
			stk.pop();
		}
		if(stk.empty()) ans += del;
		else ans += del+1;
		//cout<<seq[i]<<" "<<del<<" "<< ans<<"\n";
		stk.push({seq[i], cnt});
	}
	cout<<ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0 ; i < n ; i++) cin>>seq[i];
	sol();
}
