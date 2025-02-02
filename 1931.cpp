#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> T;
bool compare(const pair<int,int> &a, const pair<int,int> &b){
	if(a.second == b.second)return a.first < b.first;
	else return a.second < b.second;
}
int main(void){
	cin>>n;
	for (int i = 1; i <= n ; i++){
		int s, e;
		cin>>s>>e;
		T.emplace_back(s,e);
	}
	sort(T.begin(), T.end(), compare);
	int cnt = 1;
	auto [i, j] = T[0];
	for (int k = 1 ; k <n ; k++){
		auto [p,q] = T[k];
		if (j <= p){i = p;j = q; cnt++;}
		else if (p-q == 0) cnt++;
	}
	cout << cnt;
}
