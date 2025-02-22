#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int dp[100001];
int mylist[2];

void BFS() {
    dp[0] = 0;
    for(int i = 0 ; i <= n ; i++) {
        if(dp[i] == -1) continue;
        int ba = i-a;
        int bb = i-b;
        if(ba >= 0 && dp[ba] != -1){
            dp[i] = min(dp[i], dp[ba] + 1);
        }
        if(bb >= 0 && dp[bb] != -1){
            dp[i] = min(dp[i], dp[bb] + 1);
        }
    }
    if (dp[n] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dp[n] << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a >> b;
    mylist[0] = a;
    mylist[1] = b;
    for (int i = 0; i <= n; i++) {
        dp[i] = 1e9;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        for (int j = x; j <= y; j++) {
            dp[j] = -1;
        }
    }
    BFS();
    return 0;
}