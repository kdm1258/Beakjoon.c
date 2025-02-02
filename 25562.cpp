#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
void my_pow(int n){
	ll ret = 1;
	while(n--){
		cout<<ret<<" ";
		ret *= 2;
	}
}
int main(void){
	cin>>n;
	cout<<n*(n-1)/2<<"\n";
	my_pow(n);
	cout<<"\n"<<n-1<<"\n";
	for(int i = 1 ; i<= n ; i++){
		cout<<i<<" ";
	}
}
