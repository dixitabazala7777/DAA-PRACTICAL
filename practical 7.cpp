#include <iostream>
using namespace std;

int main() {
    int coins[] = {1, 2, 5};           // Available coin denominations
    int V = 11;                        // Target amount
    int dp[12];                        // DP array for amounts 0 to 11

    for (int i = 0; i <= V; i++) dp[i] = 999; // Fill with large number (infinity)
    dp[0] = 0;                         // 0 coins needed to make amount 0

    for (int i = 1; i <= V; i++) {                 // For each amount from 1 to V
        for (int j = 0; j < 3; j++) {              // Check every coin
            if (coins[j] <= i)                     // If coin value <= current amount
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]); // Take minimum coins
        }
    }
    cout << "Min Coins: " << dp[V];    // Print minimum coins for target V
    return 0;
}
