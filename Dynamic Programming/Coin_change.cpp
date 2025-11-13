/*
Problem Statement:

Given an integer array `coins` representing coin denominations and an integer `amount`,
return the number of combinations that make up that amount.
You may use an infinite number of each coin.

Time Complexity: O(n*amount)
Space Complexity: O(n*amount) or O(amount) for space optimized
*/

#include <vector>
using namespace std;

// MEMOIZATION (Top-Down DP)

int coinChangeMemoHelper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (amount == 0) return 1;      // amount achieved
    if (i < 0) return 0;            // no coins left
    if (dp[i][amount] != -1) return dp[i][amount];

    int notTake = coinChangeMemoHelper(i - 1, amount, coins, dp);
    int take = 0;
    if (coins[i] <= amount) take = coinChangeMemoHelper(i, amount - coins[i], coins, dp);

    return dp[i][amount] = take + notTake;
}

int coinChangeMemo(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return coinChangeMemoHelper(n - 1, amount, coins, dp);
}

// TABULATION (Bottom-Up DP)

int coinChangeTab(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i < n; i++) dp[i][0] = 1; // 0 amount can always be formed

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            int notTake = (i > 0) ? dp[i - 1][j] : 0;
            int take = (coins[i] <= j) ? dp[i][j - coins[i]] : 0;
            dp[i][j] = take + notTake;
        }
    }
    
    return dp[n - 1][amount];
}

