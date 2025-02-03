#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll S[60];
ll a, b;
/*string toBi(ll n) {
    string binary = "";
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary;
}*/

ll sol(ll n){
    // 1~n까지 1의 개수 return
    //cout<<toBi(n)<<"\n";
    int l = log2(n);
    if(n==0)return 0;
    return S[l] + n - pow(2,l) + 1 + sol(n & ~(1<<l)); //bitmasking
}
void setS(){
    // S[i]일때 2^i까지의 1의 개수
    S[1] = 1;
    for(int i = 2 ; i < 60 ; i++){
        S[i] = S[i-1]*2 + pow(2, i-1);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setS();
    cin>>b>>a;
    cout<<sol(b)-sol(a-1);
}