#include <bits/stdc++.h>
using namespace std;
string a,s,c;
int n, cnt=0;
string Pair[505050];
void sol(void){
	if(a.size() <= 2) {cout<<cnt;return;}
	for(int i = a.size()-2 ; i >= 0 ; i--){
		for(int j = 0 ; j < n ; j++){
			if (i+1<a.size() &&Pair[j] == a.substr(i,2)){
				if(a.substr(0,(a.size()-1)/2)==a.substr((a.size()-1)/2,(a.size()-1)/2)){
					cnt+=2;
						a = a.substr((a.size()-1)/2,(a.size()-1)/2-1);
						sol();
				}
				else {cout<<-1; return;}
			}
		}
			cnt++;
			a=a.substr(0,a.size()-1);
			sol();			
	}	
}
int main(void){
	cin>>n;
	cin>>s;
	cin>>c;
	cin>>a;
	for(int i = 0 ; i < n ; i++){
		Pair[i] = s.substr(i,1)+c.substr(i,1);
	}
	sol();
}
