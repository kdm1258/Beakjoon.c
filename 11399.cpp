#include <bits/stdc++.h>
using namespace std;
int P[1010],S[1010];
int main(void){
	int n, sum = 0;
	cin>>n;
	for (int i = 1 ; i <= n ; i++){
		cin>>P[i];
	}
	sort(P,P+n+1);
	for (int i = 1 ; i <= n ; i++){
		S[i] = S[i-1] + P[i];
		sum+=S[i];
	}
	cout<<sum;
}
