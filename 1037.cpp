#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, arr[55];
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<arr[0]*arr[n-1];
}
