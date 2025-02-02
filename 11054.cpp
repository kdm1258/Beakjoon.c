#include <bits/stdc++.h>
using namespace std;
int asc[1010];
int des[1010];
int arr[1010];
int n;
int solve(void){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j < i ; j++){
			if(arr[i] > arr[j]){
				asc[i] = max(asc[i], asc[j] + 1);
			}
			if(arr[n-i+1] > arr[n-j+1]){
				des[n-i+1] = max(des[n-i+1],des[n-j+1]+1);
			}
		}
			//cout<<asc[i]<<" "<<des[n-i+1]<<"\n";
	}
	int Max = 0;
	for(int i = 1 ; i <= n ; i++){
		if(Max < asc[i] + des[i]){
			Max = asc[i] + des[i];
		}
	}
	return Max;
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>arr[i];
		asc[i] = 1; des[i] = 1;
	}
	cout<<solve()-1;
}
