#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate S_mn
long long calculate_S_mn(int m, int n) {
    // Precompute all powers to avoid overflow
    vector<vector<long long>> powers(n + 1, vector<long long>(m + 1, 0));
    for (int j = 2; j <= n; ++j) {
        for (int i = 0; i <= m; ++i) {
            powers[j][i] = pow(i, j);
        }
    }

    long long S_mn = 0;

    // Iterate over j from 2 to n
    for (int j = 2; j <= n; ++j) {
        long long card_T_mj = 0;

        // Iterate over x and y
        for (int x = 0; x <= m; ++x) {
            for (int y = x; y <= m; ++y) { // y >= x
                long long target = powers[j][x] + powers[j][y]; // x^j + y^j

                // Check for z such that powers[j][z] == target
                for (int z = y; z <= m; ++z) { // z >= y
                    if (powers[j][z] == target) {
                        card_T_mj++;
                        break; // Stop checking further z values
                    }
                }
            }
        }

        S_mn += card_T_mj;
    }

    return S_mn;
}

int main() {
    // Example usage:
    int m ,n;
	cin>>m>>n;
    cout << calculate_S_mn(m, n) << endl;

    return 0;
}

