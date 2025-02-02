#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long int sol(int n){
		int hist[101010];
		int l[101010];
		int r[101010];
		for(int i = 1 ; i <= n ; i++){
			cin>>hist[i];
		}
		stack <pair<int ,int>> stkl;
		for(int i = 1 ; i <= n ; i++){
			while(!stkl.empty() && stkl.top().second >= hist[i]) stkl.pop();
			if(stkl.empty()) l[i] = 0;
			else l[i] = stkl.top().first;
			stkl.push(make_pair(i,hist[i]));
		}
		stack <pair<int ,int>> stkr;
		for(int i = n ; i >= 1 ; i--){
			while(!stkr.empty() && stkr.top().second >= hist[i]) stkr.pop();
			if(stkr.empty()) r[i] = n+1;
			else r[i] = stkr.top().first;
			stkr.push(make_pair(i,hist[i]));
		}
		unsigned long long int Max = 0;
		for(int i = 1 ; i <= n ; i++){
			Max = max(Max,  hist[i] * (r[i] - l[i] - 1ull));
		}
		return Max;
}
int main(void){
	cin>>n;
	while(n!=0){
		cout<<sol(n)<<"\n";
		cin>>n;
	}
}
