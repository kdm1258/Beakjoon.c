#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, k;
int d[MAX + 1];  // 거리 배열
int w[MAX + 1];  // 경로 수 배열

void BFS(int start) {
    queue<int> q;
    q.push(start);
    d[start] = 0;
    w[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int next : {u - 1, u + 1, u * 2}) {
            if (next < 0 || next > MAX) continue;

            // 처음 방문하는 경우
            if (d[next] == -1) {
                d[next] = d[u] + 1;
                w[next] = w[u];
                q.push(next);
            }
            // 동일한 최단 거리로 도달하는 경우
            else if (d[next] == d[u] + 1) {
                w[next] += w[u];
            }
        }
    }
}

int main() {
    cin >> n >> k;

    memset(d, -1, sizeof(d));

    if (n == k) {
        cout << 0 << "\n" << 1;
        return 0;
    }

    BFS(n);

    cout << d[k] << "\n" << w[k] << "\n";
    return 0;
}

