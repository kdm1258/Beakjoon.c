#include <bits/stdc++.h>
using namespace std;
string A, B;
int Dp[1010][1010];
int main(void){
	cin>>A>>B;
	int n = A.size();
	int m = B.size();

	for (int i = 0 ; i< n ; i++){
		for(int j = 0 ; j<m ; j++){
			if(A[i] == B[j]) Dp[i+1][j+1] = Dp[i][j] +1;
			else Dp[i+1][j+1] = max(Dp[i][j+1], Dp[i+1][j]);
		}
	}
	cout<<Dp[n][m];
	if (Dp[n][m] == 0) return 0;
	string S;
	for (int i = n ,j = m ; i >= 0 && j >=0;){
		if(A[i] == B[j]){
		   	S += A[i];
			i--,j--;
		}
		else if(Dp[i][j+1] > Dp[i+1][j]) i--;
		else j--;
	}
	reverse(S.begin(), S.end());
	cout<<"\n"<<S;
}
