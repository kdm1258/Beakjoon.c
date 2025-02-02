#include <bits/stdc++.h>
using namespace std;
int n, cnt;
void compare(int);
void solve(int);
int arr[5];
int main(void){
	cin>>n;
	while(n!=0){
		solve(n);
		cin>>n;
		cnt = 0;
	}
}
void solve(int n){
	while(n>0){
		arr[cnt] = n%10;
		n/=10;
		cnt++;
	}
	compare(cnt);
}
void compare(int cnt){
	for(int i = 0 ; i <cnt/2 ; i++){
		if(arr[i] == arr[cnt-i-1])continue;
		else{
			cout<<"no\n";
		   	return;
		}
	}
	cout<<"yes\n";
}
