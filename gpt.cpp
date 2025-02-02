#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
string a, s, c;
string Pair[505050];

void sol() {
    if (a.size() <= 2) {
        cout << cnt;
        return;
    }

    for (int i = a.size() - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < a.size() && Pair[j] == a.substr(i, 2)) {
                // Check if the condition for "두 배" is met
                if (i / 2 >= 1 && a.substr(0, i / 2) == a.substr(i / 2, i / 2)) {
                    cnt += 2;
                    if (i / 2 - 1 >= 0) {
                        a = a.substr(i / 2, i / 2 - 1);
                    } else {
                        a = "";
                    }
                    sol();
                    return;
                } else {
                    cout << -1;
                    return;
                }
            }
        }
        cnt++;
        a = a.substr(0, a.size() - 1);
        sol();
        return;
    }
}

int main() {
    cin >> n;
    cin >> s;
    cin >> c;
    cin >> a;

    // Construct pairs
    for (int i = 0; i < n; i++) {
        Pair[i] = s.substr(i, 1) + c.substr(i, 1);
    }

    // Start solving the problem
    sol();

    return 0;
}
