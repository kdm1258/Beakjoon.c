#include <bits/stdc++.h>
using namespace std;
int n , k;
int A[101];
int Dp[10101];
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i = 1 ; i <= n ; i++)cin>>A[i];
	for(int i = 0 ; i <= 10101 ; i++) Dp[i] = 1e9;
	Dp[0]=0;
	for (int i = 1 ; i <=n ; i++){
		for (int j = 0 ; j<=k ; j++){
			if(j-A[i] >= 0) Dp[j] = min(Dp[j], Dp[j-A[i]]+1);
		}	
	}
	cout<<(Dp[k] < 1e9 ?Dp[k]: -1);
}
