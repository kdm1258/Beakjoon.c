#include <bits/stdc++.h>
using namespace std;
int airport[101010];
int P[101010];
int g, p, cnt;
int Find(int v){
    if(v == P[v]) return v;
    else return P[v] = Find(P[v]);
}
void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    P[u] = v;
}
int sol(int t){
    int a = Find(t);
    if(a!=0){
        Union(a,a-1);
        cnt++;
        return 1;
    }
    else{
        return 0;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>g>>p;
    for (int i = 0 ; i <= g ; i++){
        P[i] = i;
    }
    int flag = 1;
    for(int i = 1 ; i<=p ; i++){
        if(flag){
            int t;
            cin>>t;
            flag = sol(t);
      }
    }
    cout<<cnt;
}