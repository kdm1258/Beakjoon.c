#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>>C (1010, vector<int>(1010,0));
void calc(int n){
	C[0][0] = 1;
	for (int i = 1 ; i <= n ; i++){
		C[i][i] = 1;
		C[i][0] = 1;
		for (int j = 1 ; j <= i ; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];	
			if(C[i][j]>=10007) C[i][j] = C[i][j]-10007;
		}
	}
}
int main(void){
	int n;
	int k;
	cin>>n>>k;
	calc(n);
	cout<<C[n][k];
}
