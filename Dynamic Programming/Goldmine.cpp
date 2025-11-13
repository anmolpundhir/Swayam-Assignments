/*
Problem Statement:

Given a grid of size m x n representing a gold mine, where each cell contains
a certain amount of gold, find the maximum amount of gold you can collect.
You can start from any row in the first column and move to the cell
diagonally up-right, right, or diagonally down-right at each step.

Time Complexity: O(m*n)
Space Complexity: varies with approach
*/

#include <vector>
#include <algorithm>
using namespace std;

// MEMOIZATION (Top-Down DP)

int goldMineMemoHelper(int i, int j, vector<vector<int>>& gold, vector<vector<int>>& dp) {
    int m = gold.size();
    int n = gold[0].size();

    if (i < 0 || i >= m || j >= n) return 0; // Out of bounds
    if (dp[i][j] != -1) return dp[i][j];

    int right = goldMineMemoHelper(i, j + 1, gold, dp);
    int rightUp = goldMineMemoHelper(i - 1, j + 1, gold, dp);
    int rightDown = goldMineMemoHelper(i + 1, j + 1, gold, dp);

    return dp[i][j] = gold[i][j] + max({right, rightUp, rightDown});
}

int goldMineMemo(vector<vector<int>>& gold) {
    int m = gold.size();
    int n = gold[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        maxGold = max(maxGold, goldMineMemoHelper(i, 0, gold, dp));
    }
    return maxGold;
}


// TABULATION (Bottom-Up DP)

int goldMineTab(vector<vector<int>>& gold) {
    int m = gold.size();
    int n = gold[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            int right = (j == n - 1) ? 0 : dp[i][j + 1];
            int rightUp = (i == 0 || j == n - 1) ? 0 : dp[i - 1][j + 1];
            int rightDown = (i == m - 1 || j == n - 1) ? 0 : dp[i + 1][j + 1];

            dp[i][j] = gold[i][j] + max({right, rightUp, rightDown});
        }
    }

    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        maxGold = max(maxGold, dp[i][0]);
    }
    return maxGold;
}

