#include <bits/stdc++.h>
using namespace std;
int S[101010];
int n;
int main(void){
	cin>>n;
	int Max = 0;
	int tmp = 0;
	for(int i = 1 ; i <= n ; i++){
		cin>>S[i];
		if(tmp < tmp+S[i]) tmp = tmp+S[i];
		else{
			if (Max < tmp) Max = tmp;
			tmp = 0;
		}
	}
	cout<<Max;
}
