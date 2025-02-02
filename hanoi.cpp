#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
void hanoi(int n, int from, int to,int rest){
	if (n == 1){
		cout<<from<<' '<<to<<'\n';
		return;	
	}
	hanoi(n-1, from, rest, to);
	cout<<from<<' '<<to<<'\n';
	hanoi(n-1, rest, to, from);
}
int main(void){
	int n = 0 ;
	cin>>n;
	for (int i = 1 ; i <n; i++) cnt = cnt*2+1;
	cout<<cnt<<'\n';
	hanoi(n,1,3,2);
}
