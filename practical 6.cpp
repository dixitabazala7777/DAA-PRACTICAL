#include <iostream>
#include <climits>
using namespace std;

int main() {
    int p[] = {10, 20, 30, 40};        // Dimensions of 3 matrices (10x20, 20x30, 30x40)
    int n = 4;                         // Size of array p
    int dp[4][4] = {0};                // DP table initialized to 0

    for (int L = 2; L < n; L++) {                  // L is chain length
        for (int i = 1; i < n - L + 1; i++) {      // i is start index
            int j = i + L - 1;                     // j is end index
            dp[i][j] = INT_MAX;                    // Set initial cost to infinity
            for (int k = i; k < j; k++) {          // Try every split point k
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]; // Calculate cost
                if (cost < dp[i][j]) dp[i][j] = cost; // Keep minimum cost
            }
        }
    }
    cout << "Min Multiplications: " << dp[1][n - 1]; // Print result
    return 0;
}
