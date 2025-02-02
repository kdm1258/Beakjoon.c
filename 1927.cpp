#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int,vector<int>, greater<int>> pq;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int tmp;
		cin>>tmp;

		if(tmp==0){
			if(pq.empty()) cout<<0<<"\n";
			else {cout<<pq.top()<<"\n"; pq.pop();} 
		}	
		else{
			pq.push(tmp);
		}
	}
}
