#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500005;
int N, K;
int C[MAXN], W[MAXN];
ll prefixSum[MAXN], prefixCount[MAXN];

void solve() {
    cin >> N >> K; 
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }
    
    for (int i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i-1] + (C[i] == 1 ? W[i] : -W[i]);
        prefixCount[i] = prefixCount[i-1] + (C[i] == 1 ? 1 : -1);
    }
   
    ll res = 0;
    map<pair<ll,ll>,int> count;
    count[{0,0}] = 1;
    ll sum = 0;
    ll cnt = 0;
    
    for(int i = 1 ; i <= N ; i++){
    	sum += C[i] == 1 ? W[i] : -W[i];
    	cnt += C[i] == 1 ? 1 :-1;
    	for(ll i = -K ; i <= K ; i++){
    		res += count[{cnt, sum - i}];
    	} 
    	count[{cnt, sum}]++;
    }
    cout<<res<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
   
}
