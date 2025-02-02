#include <bits/stdc++.h>
using namespace std;
int n, arr[1010101];
void merge(int l, int r){
	int i = l;
	int j = r;
	int size = r-l;
	vector<int> v;
	while(i<i+size && j<j+size){
		if(arr[i] >= arr[j]){
			v.push_back(arr[j]);
			j++;
		}
		else{
			v.push_back(arr[i]);
			i++;
		}
	}
	for(i ; i < i+size ; i++){
		v.push_back(arr[i]);
	}
	for(j ; j < j+size ; j++){
		v.push_back(arr[j]);
	}
	int p = 0;
	for(int k = l ; k<r ; k++){
		arr[k] = v[p];p++;
	}
}
void Sort(int l, int r){
	if (r==l) return;
	int m = (r + l)/2;
	Sort(l,m);
	Sort(m+1,r);
	merge(l,r);
}
int main(void){
	cin>>n;
	for (int i=1 ; i <= n ; i++){
		cin>>arr[i];
	}
	Sort(0,n);
	for(int i = 1 ; i <= n ; i++) cout<<arr[i]<<"\n";
}
