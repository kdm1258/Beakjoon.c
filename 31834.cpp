#include <bits/stdc++.h>
using namespace std;
int t, n, s, e;
int main(void){
	cin>>t;
	while(t--){
		cin>>n>>s>>e;
		if ((s==1 && e == n) || (s==n && e == 1)) cout<<0<<"\n";
		else if	(abs(s-e) == 1) cout<<1<<"\n";
		else if (s == 1 || s == n) cout<<1<<"\n";
		else if (e == 1 || e == n) cout<<2<<"\n";
		else cout<<2<<"\n";
	}
}

