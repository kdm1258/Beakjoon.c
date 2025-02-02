#include <bits/stdc++.h>
using namespace std;
int n,k;
int dp[101][5050];
map<int, int> m;
int sol(void){
	int MaxSpeed = 1;
	for(int i = 1 ; i < k ; i++){
	//	cout<<"i: "<<i<<"\n";
		for(int s = 1 ; s<= MaxSpeed ; s++){
	//	cout<<"s: "<<s<<"\n";
			if(dp[i+1][s] < dp[i][s]+s){ 
				if(dp[i][s] != -1) dp[i+1][s] = dp[i][s]+s;
				for(auto j : m){
					if(j.first > dp[i][s]) break;
					if(dp[i+1][s+j.second] < dp[i][s] - j.first ){
						dp[i+1][s+j.second] = dp[i][s] - j.first;
						MaxSpeed = MaxSpeed < s+j.second ? s+j.second : MaxSpeed;
	//					cout<<s<<" "<<j.second<<" "<<MaxSpeed<<"\n";
					}
				}
			}
		}
	}
	/*for(int i = 1 ; i <=4 ; i++){
		for(int j = 1 ; j <= 9 ; j++){
			cout<<"dp["<<i<<"]["<<j<<"]"<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	int tmp=0;
	for(int i = 0 ;  i <= MaxSpeed ; i++){
		tmp = max(tmp, dp[k][i]);
	}
	return tmp;
}
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		int k , v;
		cin>>k>>v;
		m.insert({k,v});
	}
/*	for(auto i : m){
		cout<<i.first<<" "<<i.second<<"\n";
	}*/
	memset(dp,-1,101*5050*sizeof(int));
	dp[0][1] = 0;
	dp[1][1] = 1;
	cout<<sol();

}
