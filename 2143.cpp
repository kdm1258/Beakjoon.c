#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n,m,cnt;
int SA[1010];
int SB[1010];
map<ll,ll> ma;
void count(int arr[]){
	for(int i = 1 ; i <= m ; i++){
		for(int j = 0 ; j< i ; j++){
			if(ma.find(SB[i]-SB[j]) != ma.end()) ma[SB[i]-SB[j]]++;
			else ma.insert({SB[i]-SB[j],1});
		}
	}
	
}
void sol(void){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < i ; j++){
			cnt+=ma[t-SA[i]+SA[j]];
		}
	}
	cout<<cnt;
}
int main(void){
	cin>>t>>n;
	for(int i = 1 ; i<=n ; i++){
		int tmp; cin>>tmp;
		SA[i] += SA[i-1] + tmp;
	}
	cin>>m;
	for(int i = 1 ; i<=m ; i++){
		int tmp; cin>>tmp;
		SB[i] += SB[i-1] + tmp;
	}
	count(SB);
	sol();
}
