#include <iostream>
using namespace std;

int main() {
    int W = 50, n = 3;                 // Bag capacity & number of items
    int val[] = {60, 100, 120};        // Values of items
    int wt[] = {10, 20, 30};           // Weights of items
    int dp[4][51] = {0};               // DP table initialized to 0

    for (int i = 1; i <= n; i++) {                 // Loop through each item
        for (int w = 1; w <= W; w++) {             // Loop through every capacity
            if (wt[i - 1] <= w)                    // If item fits in bag
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); // Pick max of include vs exclude
            else
                dp[i][w] = dp[i - 1][w];           // Else skip the item
        }
    }
    cout << "Max Value: " << dp[n][W]; // Print final answer
    return 0;
}
