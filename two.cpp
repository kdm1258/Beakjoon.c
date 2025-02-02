#include <iostream>
#include <vector>
using namespace std;
int main(void){
	int n = 0;
	int m = 0;
	int tmp = 0;
	vector<int> arr(101010);

	cin>>n>>m;
	for (int i = 1 ; i <= n ; i++){
		cin>>tmp;
		arr[i] = arr[i-1] + tmp;
	}
	int i = 0;
	int j = 0;

	for (int i = 1 ; i<=m ; i++){
		cin>>i>>j;
		cout<<arr[j]-arr[i-1]<<'\n';
	}

}
