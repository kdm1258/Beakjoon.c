#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	int A[1001];
	int D[1001];
	for(int i = 1 ; i <= N ; i++){
		cin>>A[i];
		D[i] = 1;
	}	
	for (int i = 1 ; i <= N ; i++){
		for (int j = 1 ; j< i ; j++){
			if(A[i] > A[j]){
				D[i] = max(D[i],D[j]+1);
			}
		}
	}
	int Max = 0;
	for (int i = 1 ; i <= N ; i++) Max = max(Max,D[i]);
	cout<<Max;
}
