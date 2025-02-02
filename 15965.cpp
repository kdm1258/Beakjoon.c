#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> v;
int C[8080808];
void Sieve(int n){
	for (int i = 2 ; i <= n ; i++){
		if(C[i] == 1) continue;
		v.push_back(i);
		for(int j = 2*i ; j <= n ; j+=i) C[j]=1;
	}
}
int main(void){
	cin>>k;
	Sieve(8000000);
	cout<<v[k-1];
}
