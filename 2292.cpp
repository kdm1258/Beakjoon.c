#include <bits/stdc++.h>
using namespace std;
int n,s,e;
int main(void){
	cin>>n;
	s = 1;
	e = 1;
	int cnt = 1;
	while(n<s || n>e){
		s = e+1;
		e += 6*cnt; 
		cnt++;
	}
	cout<<cnt;
}
