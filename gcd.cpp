#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int main(void){
	int n;
	int t1, t2;
	cin>>n;
	cin>>t2;
	for (int i = 1 ; i < n-2 ; i++){
		cin>>t1;
		t2 = lcm(max(t1,t2),min(t1,t2));
	}
	cout<<t2;
	return 0;
}
