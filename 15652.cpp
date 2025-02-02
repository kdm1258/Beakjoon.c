#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
void sol(int s, int index){
		if(index==m){
			for(int j = 0 ; j <m ; j++) {
				cout<<arr[j]<<" ";
			}
			cout<<"\n";
			return;
		}else{
			for(int i = s ; i <=n ; i++){
				arr[index]=i;
				sol(i,index+1);
			}
		}
}
int main(void){
	cin>>n>>m;
	sol(1,0);
}
