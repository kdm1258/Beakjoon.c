#include <bits/stdc++.h>
using namespace std;
int home[202020], N, C;
int manyrouter(int dist){
	int cnt = 1;
	int present = 1;
	for(int i = 2 ; i <= N ; i++){
		if(dist<=home[i]-home[present]) {
			cnt++; present = i;
		}
	}
	return cnt;
}
int main(void){
	cin>>N>>C;
	for(int i = 1 ; i <= N ; i++){cin>>home[i];}
	sort(home+1,home+N+1);
	int l = 1;
	int r = home[N] - home[1];
	while (l<=r){
		int mid = (l + r) / 2;
		if (manyrouter(mid)<C){
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout<<r;
}
