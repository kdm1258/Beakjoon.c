#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> A(a), B(b);

    for (int i = 0; i < a; ++i) cin >> A[i];
    for (int i = 0; i < b; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> result;
    int i = 0, j = 0;
    while (i < a && j < b) {
        if (A[i] == B[j]) {
            ++i;
        } else if (A[i] < B[j]) {
            result.push_back(A[i]);
            ++i;
        } else {
            ++j;
        }
    }
    while (i < a) {
        result.push_back(A[i]);
        ++i;
    }

    cout << result.size() << "\n";
    for (auto x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
