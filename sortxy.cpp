#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}
int main(void){
	int n = 0;
	vector <pair<int, string>> p;
	
	cin>>n;
	int age;
	string name;
	for (int i= 0 ; i < n ; i++){
		cin>>age>>name;
		p.push_back(make_pair(age, name));
	}
	stable_sort(p.begin(), p.end(),compare);
	for (int i = 0 ; i < n ; i++){
		cout<<p[i].first<<' '<<p[i].second<<'\n';
	}
}
