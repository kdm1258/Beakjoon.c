#include <bits/stdc++.h>
using namespace std;
int n, m, q, num;
int V[101010];
int res[101010];
int P[101010];
void Init(int n){
    for(int i = 1 ; i <= n ; i++){
        P[i]=i;
    }
}
int Find(int v){
    if(v==P[v]) return v;
    return P[v] = Find(P[v]);
}
void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u != v) P[u] = v;
}
int sol(){
    for(int s = 1 ; s <= n ; s++){
        if(V[s]==1){
            res[Find(s)]++;
        }
        else{
            res[Find(s)]--;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    Init(n);
    for(int i = 1 ; i <= n ; i++){
        cin>>V[i];
    }
    for(int i = 0 ; i < m ; i++){
        int s, e;
        cin>>s>>e;
        Union(s,e);
    }
    sol();
    for(int i = 0 ; i < q ; i++){
        int s; cin>>s;
        if(res[P[s]]>0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}