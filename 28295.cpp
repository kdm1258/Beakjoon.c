#include <bits/stdc++.h>
using namespace std;
int main(void){
	int tmp;
	for(int i = 0 ; i < 10 ; i++){
		int t;
		cin>>t;
		tmp += t;
		tmp %= 4;
	}
	if(tmp==0) cout<<"N";
	else if(tmp == 1) cout<<"E";
	else if (tmp==2) cout<<"S";
	else cout<<"W";
}
