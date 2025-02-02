#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> tree;
int n;
int m;
ll max_h = 0;

ll isH(ll k){
    ll M=0;
    for (int i = 0 ; i < n ; i++){
        if(k < tree[i]){
            M+=(tree[i]-k);    
        }
    }
    return M;
}

ll isEnough(ll key){
    ll min_h = 0;
    ll result = 0;
    while(min_h <= max_h){
        ll mid = (min_h + max_h)/2;
        if (isH(mid) >= key) {
            result = mid;
            min_h = mid + 1;
        }
        else {
            max_h = mid - 1;
        }
    }
    return result;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    cin>>m;
    for (int i = 0 ; i < n; i++){
        ll tmp;
        cin>>tmp;
        max_h = max(max_h,tmp);
        tree.push_back(tmp);
    }
    
    cout<<isEnough(m);
    return 0;
}
