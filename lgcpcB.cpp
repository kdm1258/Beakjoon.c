
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, t, O[505050], T[505050];
ll S[50505];
bool cmp(int a, int b){
	if (O[b] - O[a-1] - T[b] + T[a-1] == 0 &&(abs(S[b]-S[a-1])<=k)){
		return true;
	}
	else return false;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(int i = 1 ; i <= t ; i++){
		int ret = 0;
		cin>>n>>k;
		for(int j = 1 ; j <= n ; j++){
			int tmp; cin>>tmp;
			if(tmp == 1){ O[j] = O[j-1]+1; T[j] = T[j-1];}
			else{ O[j] = O[j-1]; T[j] = T[j-1]+1;}
		}
		for(int j = 1 ; j <= n ; j++){
			int tmp; cin>>tmp;
			if(O[j] != O[j-1]) S[j] = S[j-1] + tmp;
			else S[j] = S[j-1] - tmp;
		}
	
		for(int j = 2 ; j <= n ; j++){
			for(int k = 1 ; k < j ; k++){
				if(cmp(k, j)) ret++;
			}
		}
		cout<<ret<<"\n";
	}
}

