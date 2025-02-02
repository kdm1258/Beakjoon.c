#include <bits/stdc++.h>
using namespace std;
vector<char> v;
void can(int n){
	if(n==0){
		cout<<"-";
		return;
	}
	can(n-1);
	int tmp=1;
	for(int i = 0 ; i < n-1 ; i++) tmp*= 3;
	for (int i = 0 ; i < tmp ; i++)	cout<<' ';
	can(n-1);
}
int main(void){
	int n;
	while(true){
		cin>>n;
		if(cin.eof() ==true) break;
		can(n);
		cout<<'\n';
	}
}
