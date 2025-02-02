#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int flag=1;
int my_sigma(ll a, ll b){
	ll sum_a=0;
	ll sum_b=0;
	while(a!=0 && b!=0){
		sum_a += a%10;
		sum_b += b%10;
		a/=10;
		b/=10;
	}
	if (a<=b+1 || b<=a+1){return 0;}
	return 1;
}
void sol(ll tmp){
	if(tmp%2==0) cout<<tmp/2<<" "<<tmp/2<<"\n";
	else{
		ll x = (tmp+1)/2;
		ll y = (tmp-1)/2;
		while(flag){
			x++;
			y--;
			flag = my_sigma(x,y);
		}
		cout<<x<<" "<<y<<"\n";
	}
}
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		ll tmp; cin>>tmp;
		if(tmp==1) cout<<1<<" "<<"\n";
		else sol(tmp);
	}
}
