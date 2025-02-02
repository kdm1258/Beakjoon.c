#include <bits/stdc++.h>
using namespace std;
int n;
int dp[4];
int dp_min[3][4];
int dp_max[3][4];
void my_min(){
		dp_min[2][1] = dp[1] + min(dp_min[1][1],dp_min[1][2]);
		dp_min[2][2] = dp[2] + min(min(dp_min[1][1],dp_min[1][2]),min(dp_min[1][2],dp_min[1][3]));
		dp_min[2][3] = dp[3] + min(dp_min[1][2],dp_min[1][3]);

		dp_min[1][1] = dp_min[2][1];
		dp_min[1][2] = dp_min[2][2];
		dp_min[1][3] = dp_min[2][3];
}
void my_max(){
		dp_max[2][1] = dp[1] + max(dp_max[1][1],dp_max[1][2]);
		dp_max[2][2] = dp[2] + max(max(dp_max[1][1],dp_max[1][2]),max(dp_max[1][2],dp_max[1][3]));
		dp_max[2][3] = dp[3] + max(dp_max[1][2],dp_max[1][3]);

		dp_max[1][1] = dp_max[2][1];
		dp_max[1][2] = dp_max[2][2];
		dp_max[1][3] = dp_max[2][3];
}

int main(void){

	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= 3 ; j++){
			cin>>dp[j];
		}
			my_min();
			my_max();
	}
	cout<<max(max(dp_max[1][1],dp_max[1][2]),max(dp_max[1][3],dp_max[1][2]))<<" "<<min(min(dp_min[1][1],dp_min[1][2]),min(dp_min[1][2],dp_min[1][3]));
}
