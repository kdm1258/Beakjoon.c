#include <bits/stdc++.h>
using namespace std;
int main(void){
	priority_queue<int,vector<int>,greater<>> pq;
	int n; cin>>n;
	for(int i = 1 ; i <= n*n ; i++){
		int tmp; cin>>tmp;
		pq.push(tmp);
		if (pq.size() > n) pq.pop();
	}
	cout<<pq.top();
}
