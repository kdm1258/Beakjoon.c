#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		q.emplace(i);
	}
	while(q.size() > 1){
		q.pop();
		q.emplace(q.front()); q.pop();
	}
	cout<<q.front();
}
