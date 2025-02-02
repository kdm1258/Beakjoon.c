#include <bits/stdc++.h>
using namespace std;
int Dp[1010101] = {0};
int Way[1010101] = {0};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	if(n==1){
		cout<<0<<"\n"<<1;
		return 0;
	}
	for (int i = 2 ; i <= n ; i++){
		Dp[i] = Dp[i-1]+1;	
		Way[i] = i-1;
		if((i % 3 == 0) && Dp[i/3]+1 < Dp[i]){
			Dp[i] = Dp[i/3]+1;
			Way[i] = i/3;
		}
		if((i % 2 == 0) && Dp[i/2]+1 < Dp[i]){
			Dp[i] = Dp[i/2]+1;
			Way[i] = i/2;
		}
	}
	cout<<Dp[n]<<"\n";
	int cur = n;
    	cout << cur << " "; // 첫 번째 숫자 출력
   	 for (int i = 1; i < Dp[n]; i++) {
       		 cur = Way[cur]; // 다음 숫자로 이동
      		  cout << cur << " "; // 다음 숫자 출력
    	}
    	cout<<1;
}
