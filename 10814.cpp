#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, string>> v;
bool compare (pair<int, string> a, pair<int, string> b){
	return a.first<b.first;
}
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		int age;
		string name;
		cin>>age>>name;
		v.push_back({age,name});
	}
	stable_sort(v.begin(), v.end(), compare);
	for(int i = 0 ; i < n ; i++){
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
}
