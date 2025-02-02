#include<bits/stdc++.h>
using namespace std;
int a, b;
void sol(int a, int b, int cnt){
	if(a>b){ cout<<-1; return;}
	else if(a == b) {cout<<cnt; return;}
	if(b%10 == 1){
		sol(a,b/10, cnt+1);
	}
	else if(b%2 == 0){
		sol(a,b/2, cnt+1);
	}
	else{cout<<-1; return;}
}
int main(void){
	cin>>a>>b;
	sol(a,b,1);
}
