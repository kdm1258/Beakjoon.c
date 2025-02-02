#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
ll res;
int w[101010];
ll cc[101010];
void Myprint(int b){
 	if(w[b] != -1){
		res+=cc[b];
		Myprint(w[b]);
	}
	else{
		cout<<res<<"\n";
	}
}
void sol(int b, int c){
		cc[b]+=c;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (int i = 1 ; i <= n ; i++){
		int tmp;
		cin>>tmp;
		w[i] = tmp;
	}
	for(int i = 0 ; i < m ; i++){
		int a, b, c;
		cin>>a;
		res = 0;
		if(a==1){cin>>b>>c;sol(b,c);}
		else {cin>>b; Myprint(b);}
	}
}
