#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		int tmp; cin>>tmp; v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	int tmp = 0;
	for (auto a : v){
		tmp += a;
		sum += tmp;
	} cout<<sum;
}
