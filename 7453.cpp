#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll result;
int A[4000], B[4000], C[4000], D[4000];
vector<ll> AB;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(A[i] + B[j]);
        }
    }

    sort(AB.begin(), AB.end());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll S = -(C[i] + D[j]);
            auto lower = lower_bound(AB.begin(), AB.end(), S);
            auto upper = upper_bound(AB.begin(), AB.end(), S);
            result += upper - lower;
        }
    }

    cout << result << '\n';
    return 0;
}