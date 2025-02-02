#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1010101];
int main(void){
	cin>>n;
	for(int i = 2 ; i <= n ; i++){
		int Min=arr[i-1];
		if(i%2==0 && Min > arr[i/2]) Min = arr[i/2];
		if(i%3==0 && Min > arr[i/3]) Min = arr[i/3];
		arr[i] = 1 + Min;
	}
	cout<<arr[n];
}
