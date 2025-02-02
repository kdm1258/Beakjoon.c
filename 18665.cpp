#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
set <ll> S; 
int c;
bool find(ll k){
/*	sort(S.begin(), S.end());
	int l = 0;
	int r = S.size();
	while(l<=r){
		int mid = (l+r) / 2;
		if (S[mid] == k) return true;
		else if(S[mid] < k){
			l = mid +1;
		}
		else{
			r = mid -1;
		}
	}
	return false;*/
	return S.find(k) != S.end();
}
void sol(ll k){
	c++;
	ll root = (ll)sqrt(k);
	if(root*root!=k) root++; 
	if(!find(root)){
		sol(root);
		S.insert(root);
	}
	if(!find(root*root-k)){
		sol(root*root-k);
		S.insert(root*root-k);
	}
	cout<<root<<" "<<root*root-k<<"\n";
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	S.insert(0);
	S.insert(1);
	S.insert(2);
	sol(n);

	assert(c<=43);
}
