#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int chArr[10];
int arr[10];
int c[10];
void sol(int cnt){
	if(cnt==m){
//		if(!equal(chArr,chArr+m,arr)){
			for(int i = 0 ; i < m ; i++){
				cout<<arr[i]<<" ";
//				chArr[i] = arr[i];
			}
			cout<<"\n";
			return;

//		else{cnt++;	return;}
	}
	int last = 0;
	for(int i = 0 ; i < n ; i++){
		if(c[i]==0 && last != v[i]){
			arr[cnt] = v[i];
			last = arr[cnt];
			c[i] = 1;
			sol(cnt+1);
			c[i] = 0;
		}
	}
}
int main(void){
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		int tmp; cin>>tmp;
			v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	sol(0);
}
