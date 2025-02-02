#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, p;
ll res = 1;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>p;
	for (int i = 1 ; i <= n ; i++){
		res *= i%p;
		res%=p;
	}
	cout<<res;
}
