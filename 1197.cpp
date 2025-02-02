#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int maxGCDSum(const vector<int>& arr) {
    int n = arr.size();
    int answer = 0;

    // Iterate over all possible k values
    for (int k = 1; k <= n; ++k) {
        int leftGCD = 0, rightGCD = 0;
        int leftSize = k, rightSize = n - k;

        // Calculate GCD for left side
        for (int i = 0; i < leftSize; ++i) {
            leftGCD = (i == 0) ? arr[i] : gcd(leftGCD, arr[i]);
        }

        // Calculate GCD for right side
        for (int i = n - 1; i >= rightSize; --i) {
            rightGCD = (i == n - 1) ? arr[i] : gcd(rightGCD, arr[i]);
        }

        // Update answer with maximum GCD sum found
        answer = max(answer, leftGCD + rightGCD);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = maxGCDSum(arr);
    cout << result << endl;

    return 0;
}
