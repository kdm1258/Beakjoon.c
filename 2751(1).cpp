#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(void){
	int n;
	cin>>n;

	for(int i = 0 ; i < n ; i++){int tmp; cin>>tmp;  v.push_back(tmp);}
	sort(v.begin(), v.end());
	for (auto a : v) cout<<a<<"\n";
}
