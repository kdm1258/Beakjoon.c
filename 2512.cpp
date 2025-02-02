#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll M,sum;
int N,l,r,Max;
ll budget[10101];
bool YorN(int bud){
	sum=0;
	for(int i = 0 ; i < N ; i++){
		if(budget[i]<=bud) sum+=budget[i];
		else sum += bud;
	}
	if (sum>M) return false;
	else return true;
}
void bisearch(void){
	while(l<=r){
		int mid = (l+r)/2;
		if (YorN(mid)) l = mid+1;
		else r = mid-1;
	}
	cout<<r;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>N;
	for(int i = 0 ; i < N ; i++){cin>>budget[i]; sum += budget[i];
		if(Max<budget[i]) Max = budget[i];
	}
	cin>>M;
	if(sum<=M){ cout<<Max; return 0;}
	l = 0; r = sum;
	bisearch();
}
