#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll S[55];
ll a, b;

ll sol(ll n) {
    // 1~n까지 1의 개수 return
    ll res = 0;
    while (n > 0) {
        int l = log2(n);
        res += S[l] + n - (1LL << l) + 1LL;
        //n = n & ~(1LL << l); 빼기연산이 더 빠르대
        n -= (1LL << l);
    }
    return res;
}

void setS() {
    // S[i]일때 2^i까지의 1의 개수
    S[1] = 1;
    for (int i = 2; i < 55; i++) {
        S[i] = S[i-1] * 2 + (1LL << (i-1));
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setS();
    cin >> b >> a;
    cout << sol(b) - sol(a - 1);
    return 0;
}