#include <iostream>
#include <algorithm>
using namespace std;
int A[100001];
int n, m;
int in;
int exist(int in){
	int start = 0;
	int end = n-1;
	while(start<=end){
		int mid = (end+start)/2;
		if (in==A[mid]) return 1;
		else if (in < A[mid])	end = mid-1;
		else start = mid + 1;
	}
	return 0;
}
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i = 0 ; i<n ; i++){
		cin>>A[i];
	}
	sort(A,A+n);
	cin>>m;
	for (int i = 0 ; i<m ; i++){
		cin>>in;
		cout<<exist(in)<<'\n';
	}
}
