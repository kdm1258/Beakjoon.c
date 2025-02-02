#include <bits/stdc++.h>
using namespace std;
int n, m, tot, cnt;
int main(void){
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		int tmp; cin>>tmp;
		tot += tmp;
		if(tot<0) tot = 0;
		cnt += (tot >= m ? 1 : 0);
	}
	cout<<cnt;
}
