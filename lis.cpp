#include <bits/stdc++.h>
using namespace std;
int Dp[1010];
int A[1010]={0};
int S[1010];
int lis[1010];

int main(void){
	int n;
	cin>>n;
	int maxLen = 0;
   	 int lastIdx = 0;
    	int lisSize = 0;
	for(int i = 1 ; i<=n ;i++)cin>>A[i];
	for (int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(A[i]>A[j]&&(Dp[i]<Dp[j]+1)){
				Dp[i] = Dp[j]+1;
				S[i] = j;
			}
		}
		if (Dp[i] > maxLen) {
           		maxLen = Dp[i];
            		lastIdx = i;
       		}
	}
	cout<<maxLen<<"\n";
	int curIdx = lastIdx;
	while (curIdx != 0) {
		lis[lisSize++] = A[curIdx];
		curIdx = S[curIdx];
    	}
	for (int i = lisSize - 1; i >= 0; i--) {
		cout << lis[i] << " ";
    	}
}
