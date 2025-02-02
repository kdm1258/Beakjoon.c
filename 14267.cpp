#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> tree[101010];
int w[101010];
int dp[101010];
void sol(){
	dp[1] = w[1];
	for(int i = 1 ; i <= n ; i++){
		for(auto a : tree[i]){
			dp[a] = dp[i] + w[a];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout<<dp[i]<<" ";
	}	
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int tmp; cin>>tmp; //-1 날리기
	for(int i = 2 ; i <= n ; i++){
		cin>>tmp; 
		tree[tmp].push_back(i);
	}
	for(int i = 1 ; i <= m ; i++){
		int a, b; cin>>a>>b;
		w[a] += b;
	}
	sol();
}
