#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int n;
ll A[1010101];
ll N[1010101];
int I[1010101];
int cnt = 0;
int bisearch(int l, int r, int m) {
    while(l < r) {
        int mid = (l + r) / 2;
        if(N[mid] < m) l = mid + 1;
        else r = mid;
    }
    return l;
}
void insert(ll t, int j){
	int Index = 0;
	if(N[cnt] >= t){
		Index = bisearch(1,cnt,t);
	}
	else {
		cnt++;
		Index = cnt;
	}
	N[Index] = t;
	I[j] = Index;
}
void sol(void){
	for(int i = 1 ; i <= n ;i++){
		insert(A[i], i);
	}
	cout<<cnt<<"\n";
	stack<ll> stk;
	for(int i = n ; i>=1 ; i--){
		if(I[i] == cnt) {
			stk.push(A[i]);
			cnt--;
		}
	}
/*	for(int i = 1 ; i<= n ; i++){
		cout<<I[i]<<" ";
	}cout<<"\n";*/
	while(!stk.empty()){
		ll tmp = stk.top();
		cout<<tmp<<" ";
		stk.pop();
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0 ; i <= n ; i++) N[i] = -1000000001;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>A[i];
	}
	sol();
}
