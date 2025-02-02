#include <bits/stdc++.h>
using namespace std;
int n,m;
map<int, int> ma;
int arr[500001];
int main(void){
	cin>>n;
	for(int i=0 ; i< n ; i++){
		int tmp; cin>>tmp;
		if(!(ma.find(tmp)==ma.end())){
			ma[tmp]++;
		}
		else{
			ma.insert({tmp,1});
		}
	}
	cin>>m;
	for(int i = 0 ; i < m; i++){
		int tmp;
		cin>>tmp;
		if(!(ma.find(tmp) == ma.end())){
			cout<<ma[tmp]<<" ";
		}
		else cout<<0<<" ";
	}
}
