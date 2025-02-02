#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int s, e, w;
};

int n, m;
vector<Edge> edges;
ll D[505];

bool bellmanFord(int start) {
    for (int i = 1; i <= n; i++) {
        D[i] = LLONG_MAX;
    }
    D[start] = 0;

    for (int it = 1; it <= n; it++) {
        bool isChanged = false;
        for (const auto& edge : edges) {
            if (D[edge.s] == LLONG_MAX) continue;
            if (D[edge.e] > D[edge.s] + edge.w) {
                D[edge.e] = D[edge.s] + edge.w;
                isChanged = true;
            }
        }
        if (!isChanged) break; 
        if (it == n && isChanged) return false; 
    }
    return true;
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    if (!bellmanFord(1)) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= n; i++) { 
            if (D[i] == LLONG_MAX) {
                cout << -1 << endl; 
            } else {
                cout << D[i] << endl; 
            }
        }
    }
    return 0;
}
