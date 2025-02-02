#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll zero, res;
vector<pair<int, int>> arr;
bool compare(const pair<int, int>& a, const pair<int, int>& b){
	double x, y;
	x = (double)a.second / a.first; y = (double)b.second / b.first;
	if(x < y) return true;
	else return false;
}
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		double a, b;
		cin>>a>>b;
		if(a!=0) {arr.push_back({a,b});}
		else {zero += b; zero %= 40000;}
	}
	sort(arr.begin(), arr.end(), compare);
	for(auto [i, j] : arr){
		res += (res * i % 40000 + j) % 40000;
	}
	res += zero; 
	res %= 40000;
	cout<<res;
}
