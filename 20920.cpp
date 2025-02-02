#include <bits/stdc++.h>
using namespace std;
vector<string> dic;
map<string, int> Map;
int n, m;
bool compare(const string &a, const string &b){
	if(Map[a] != Map[b]){
		return Map[a] > Map[b];
	}
	else if (a.size() != b.size()){
		return a.size() > b.size();
	}
	else{
		return a < b;
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 0 ; i<n ; i++){
		string str;
		cin>>str;
		if (str.size()>=m){
		   	Map[str]++;
			if(Map[str]==1)dic.emplace_back(str);
		}
	}
	sort(dic.begin(), dic.end(), compare);
	for (auto i : dic){
		cout<<i<<" "<<"\n";
	}
}
