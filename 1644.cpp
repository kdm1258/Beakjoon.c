#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sheive[4000001];
ll n, c;
ll S[1010101];
void era(void){
	for(int i = 2 ; i <= 4000000 ; i++){
		sheive[i]=1;
	}
	for (int i =  2 ; i*i <= 4000000 ; i++){
		if(sheive[i] == 1){
			for(int j = i*i ; j<=4000000 ; j+=i){
				sheive[j] = 0;	
			}
		}
	}
	for(int i = 2 ; i <= 4000000 ; i++){
		if(sheive[i] == 1) c++;
	}
}
void Sum(void){
	int cnt = 0;
	for(int i = 0 ; i <= 4000000 ; i++){
		if(sheive[i] == 1){
			cnt++;
			S[cnt] = i+S[cnt-1];
		}
	}
}
void sol(int n){
	int i = 1;
	int j = 0;
	int cnt = 0;
		while(i<=c){
			if(S[i] - S[j] == n){
				cnt++;
				cout<<S[i]<<" "<<S[j]<<"\n";
				i++;
			}
			else if(S[i] - S[j] < n){
				i++;
			}
			else{
				j++;
			}
		}
	cout<<cnt;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	era();
	Sum();
	sol(n);
}
