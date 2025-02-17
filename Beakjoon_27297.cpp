#include <bits/stdc++.h>
using namespace std;
int main(void){
	int n = 0;
	int m = 0;
	int mid = 0;
	long long arr[1001][1001];
	long long sum[1001];
	cin>>n>>m;
	mid =m/2;

	for (int i = 0; i < m ; i++){
		for (int j = 0 ; j < n ; j++){
			cin>>arr[j][i];
		}
	}

	for (int i = 0; i< n ; i++){
			sort(&arr[i][0],&arr[i][m]);
	}
	for (int i = 0 ; i<n ; i++){
		for (int j = 0 ; j< m ; j++){
			sum[i] += abs(arr[i][mid] - arr[i][j]);
		}
	}
	for (int i = 0 ; i <n ; i++) cout<<sum[i]<<'\n';
	cout<<accumulate(&sum[0],&sum[n],(long long)0)<<'\n';
	for (int i = 0 ; i < n ; i++) cout<<arr[i][mid]<<' ';
}
	
