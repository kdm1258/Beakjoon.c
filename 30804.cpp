#include <bits/stdc++.h>
using namespace std;
int n;
int arr[202020];
	int c[10];
void sol(void){
	int first = 0, second = 0;
	int i = 1;
	int j = 0;
	int v = 0;
	int index = 0;
	int Max = 0;
	for(i ; i <= n ; i++){
		if(c[arr[i]]==0) v++;
		c[arr[i]] = i;
		if(v>2){
			int tmp = INT_MAX;
			for(int k = 1 ; k<= 9 ; k++){
				if(tmp > c[k] && c[k] !=0){
					tmp = c[k];
					j = tmp;
					index = k;
				}
			}
			c[index] = 0;
			v--;
		}
	//	for(int i = 1 ; i <= 9 ; i++) cout<<c[i]<<" ";cout<<"\n";
		Max=max(i-j,Max);
	}
	cout<<Max;
}
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>arr[i];
	}
	sol();
}
