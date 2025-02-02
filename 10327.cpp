#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll n;
ll Fibo_a[50];
ll Fibo_b[50];
void sol(ll n){
	for(int i = 45; i >= 0 ; i--){
		if(Fibo_a[i] + Fibo_b[i] > n) continue;
		else{
			for (int b = 1 ; b <= n ; b++){
				ll tmp = n-b*Fibo_b[i];
				if(tmp<=0) break;
				if(tmp%Fibo_a[i]==0 && tmp/Fibo_a[i]<=b){
					cout<<tmp/Fibo_a[i]<<" "<<b<<"\n";
					return;
				}
			}
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Fibo_a[0] = 1;Fibo_a[1] = 0;
	Fibo_b[0] = 0;Fibo_b[1] = 1;
	for (int i = 2 ; i<=50 ; i++){
		Fibo_a[i] = Fibo_a[i-1] + Fibo_a[i-2];
		Fibo_b[i] = Fibo_b[i-1] + Fibo_b[i-2];
	}
	cin>>t;
	for(int i = 1 ; i<= t ; i++){
		cin>>n;
		sol(n);
	}

}
