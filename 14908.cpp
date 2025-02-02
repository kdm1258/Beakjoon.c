#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, pair<int, int>>> v;
bool compare(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b){
	double x = (double)a.second.first / a.second.second;
	double y = (double)b.second.first / b.second.second;
	if(x==y){
		return a.first < b.first;
	}
	else if(x<y) return true;
	else return false;
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		int x, y; cin>>x>>y;
		v.push_back(make_pair(i,make_pair(x,y)));
	}
	sort(v.begin(), v.end(), compare);
	for(int i = 0 ; i < n ; i++){
		cout<<v[i].first<<" ";
	}
}
