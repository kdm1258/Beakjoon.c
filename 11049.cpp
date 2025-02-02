#include <bits/stdc++.h>
using namespace std;
int n;
int dp[505][505];
vector<pair<int,int>> v;
int sol(void){

	for(int L = 1 ; L<n ; L++){
		for(int i = 0 ; i < n-L  ; i++){
			int j = L+ i;
			//cout<<i<<" "<<j<<"\n";
			for(int k = i ; k <= j-1 ; k++){
				int tmp = dp[i][k] + dp[k+1][j] + v[i].first * v[k].second * v[j].second;
				if(dp[i][j] > tmp) dp[i][j] = tmp;
			}
		}
	}
	return dp[0][n-1];
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0 ; i < n-1 ; i++){
		for(int j = i+1 ; j < n ; j++){
			dp[i][j]=INT_MAX;
		}
	}
	for(int i = 0 ; i < n ; i++){
		int t1,t2;
		cin>>t1>>t2;
		v.push_back({t1,t2});
	}
	cout<<sol();
}
