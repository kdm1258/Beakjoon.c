#include <bits/stdc++.h>
using namespace std;
vector<int> check;
void pri(int n){
	check.resize(n+1, false);
	for (int i = 2 ; i <= n ; i++){
		if (!check[i]){
			check[i] = i;
			for (int j = i ; j <= n ; j+=i){
				check[j] = i;
			}
		}
	}
}
void factorization(int k){
	stack<int> stack;
	while(k>1){
		stack.push(check[k]);
		k/=check[k];
	}
	while(!stack.empty()){
		cout<<stack.top()<<' ';
		stack.pop();
	}
	cout<<'\n';	
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin>>n;
	pri(10000000);
/*	for (int i = 5000 ; i <=10000 ; i++){
		cout<<check[i]<<' ';
		if (check[i] == 0) cout<<"\n=========="<<'\n'<<i<<'\n';
	}*/
	for (int i = 0 ; i<n ; i++){
		int k = 0;
		cin>>k;
		factorization(k);
	}
}
