#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int n;
int dice[6] ;
ll sol(int n){
 	int m = 0;
	int m1 = INT_MAX;
	int m2 = INT_MAX;
	int m3 = INT_MAX;
	if(n==1){
		int s = 0;
		for(int i = 0 ; i < 6 ; i++){
			m = max(m,dice[i]);
			s += dice[i];
		}
		return s - m;
	}
	else{
		for(int i = 0 ; i < 6 ; i++){m1 = min(m1 ,dice[i]);}
		m3 = min(m3,dice[0]+dice[1]+dice[2]);
		m3 = min(m3,dice[0]+dice[1]+dice[3]);
		m3 = min(m3,dice[0]+dice[2]+dice[4]);
		m3 = min(m3,dice[0]+dice[4]+dice[3]);
		m3 = min(m3,dice[5]+dice[1]+dice[2]);
		m3 = min(m3,dice[5]+dice[1]+dice[3]);
		m3 = min(m3,dice[5]+dice[2]+dice[4]);
		m3 = min(m3,dice[5]+dice[4]+dice[3]);

		m2 = min(m2,dice[0]+dice[1]);
		m2 = min(m2,dice[0]+dice[2]);
		m2 = min(m2,dice[0]+dice[3]);
		m2 = min(m2,dice[0]+dice[4]);
		m2 = min(m2,dice[1]+dice[3]);
		m2 = min(m2,dice[1]+dice[2]);
		m2 = min(m2,dice[2]+dice[4]);
		m2 = min(m2,dice[3]+dice[4]);
		m2 = min(m2,dice[5]+dice[1]);
		m2 = min(m2,dice[5]+dice[2]);
		m2 = min(m2,dice[5]+dice[3]);
		m2 = min(m2,dice[5]+dice[4]);
		//cout<<m3<<" "<<m2<<" "<<m1<<"\n";
		return m3*4ull + m2*((n-1ull)*4 + (n-2ull)*4) + m1*((n-2)*(n-1ull)*4+(n-2ull)*(n-2));
	}
}
int main(void){
	cin>>n;
	for(int i = 0 ; i < 6 ; i++){
		cin>>dice[i];
	}
	cout<<sol(n);
}
