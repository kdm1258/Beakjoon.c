#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int n;
ld s;
vector<pair<ld, ld>> dot;
ld cross(pair<ld,ld> p, pair<ld,ld> p1, pair<ld, ld> p2){
	ld x1 = p.first;
	ld y1 = p.second;
	ld x2 = p1.first;
	ld y2 = p1.second;
	ld x3 = p2.first;
	ld y3 = p2.second;

	return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2;
}
ld sol(pair<ld,ld> p){
	ld sx = p.first;
	ld sy = p.second;
	for(int i = 2 ; i < n ; i++){
		s+=cross(p, dot[i-1], dot[i]);
	}
	return abs(s);
}
int main(void){
	cin>>n;
	for(int i = 0 ; i< n ;i++){
		ld x,y;
		cin>>x>>y;
		dot.push_back({x,y});
	}
	cout<<fixed;
	cout.precision(1);
	cout<<sol(dot[0]);
}
