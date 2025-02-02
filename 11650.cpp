#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
bool compare(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first){
		if(a.second <= b.second){
			return true;
		}
		else return false;
	}
	else if(a.first > b.first) return false;
	else{return true;}
}
int main(void){
	cin>>n;
	for(int i = 1 ; i <=n ; i++){
		int x,y;cin>>x>>y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end(), compare);
	for(auto [a,b] : v) cout<<a<<" "<<b<<"\n";
}
