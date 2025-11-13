/*
Problem Statement:

Given an integer array `coins` representing coin denominations and an integer `amount`,
return the minimum number of coins needed to make up that amount.
If it is not possible to make the amount, return -1.
You may use an infinite number of each coin.

Time Complexity: O(n*amount)
Space Complexity: O(n*amount) or O(amount) for space optimized
*/

#include <vector>
#include <algorithm>
using namespace std;

// MEMOIZATION (Top-Down DP)

int coinChange2MemoHelper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (amount == 0) return 0;       // amount achieved, 0 coins needed
    if (i < 0) return 1e9;           // no coins left, impossible
    if (dp[i][amount] != -1) return dp[i][amount];

    int notTake = coinChange2MemoHelper(i - 1, amount, coins, dp);
    int take = 1e9;
    if (coins[i] <= amount) take = 1 + coinChange2MemoHelper(i, amount - coins[i], coins, dp);

    return dp[i][amount] = min(take, notTake);
}

int coinChange2Memo(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int res = coinChange2MemoHelper(n - 1, amount, coins, dp);
    return (res >= 1e9) ? -1 : res;
}

// TABULATION (Bottom-Up DP)

int coinChange2Tab(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

    for (int i = 0; i < n; i++) dp[i][0] = 0; // 0 amount requires 0 coins

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            int notTake = (i > 0) ? dp[i - 1][j] : 1e9;
            int take = (coins[i] <= j) ? 1 + dp[i][j - coins[i]] : 1e9;
            dp[i][j] = min(take, notTake);
        }
    }

    return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
}