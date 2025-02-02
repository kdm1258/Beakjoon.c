#include <bits/stdc++.h>
using namespace std;
int main(void){
	int n = 0;
	int right = 0;
	int left = 1;
	cin>>n;
	right = n;
	for (int i = 1 ; i <= n ; i++){
		if (i%2 == 1) cout<<right--<<' ';
		else cout<<left++<<' ';
	}

}
