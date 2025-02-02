#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr,int mid, int l, int r){
	int n1 = mid-l+1 ;
	int n2 = r-mid;

	vector<int> L(n1), R(n2);
	for (int i = 0 ; i < n1 ; i++){
		L[i] = arr[l+i];
	}
	for (int j = 0 ; j < n2 ; j++){
		R[j] = arr[mid+1+j];
	}
	
	int i = 0, j = 0, k = l;
	while(i<n1 && j<n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = R[j];
		k++;
		j++;
	}
}
void mergesort(vector<int>& arr, int l , int r){
	if (l<r){
		int mid =(l + r)/2;

		mergesort(arr, l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,mid,l,r);
	}
}
int main(void){
	int n = 0;
	int tmp = -1;
	int r = 0;
	int l = 0 ;
	int m = 0;
	vector<int> arr(1010101);
	cin>>n;
	r = n-1;
	for (int i = 0 ; i < n ; i++){
		cin>>tmp;
		arr[i] = tmp;
	}
	mergesort(arr,l,r);
	
	for (int i = 0 ; i < n ; i++){
		cout<<arr[i]<<'\n';
	}
}
