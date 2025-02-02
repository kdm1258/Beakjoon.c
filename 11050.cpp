#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(void){
	cin>>n>>k;
	long long res = 1;
	int tmp = 1;
	while (k+1!=tmp){
		res *= n;
		res /= tmp;
		n--; tmp++;
	}	
	cout<<res;
}
