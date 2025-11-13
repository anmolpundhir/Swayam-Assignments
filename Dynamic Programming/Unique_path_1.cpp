/*
Problem Statement:

Given a grid of size m x n, find the number of unique paths from the top-left
corner (0,0) to the bottom-right corner (m-1,n-1). You can only move either
down or right at any point.

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include <vector>
using namespace std;

// MEMOIZATION (Top-Down DP)

int uniquePathsMemoHelper(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;           // Base case: start cell
    if (i < 0 || j < 0) return 0;             // Out of bounds
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = uniquePathsMemoHelper(i - 1, j, dp) + uniquePathsMemoHelper(i, j - 1, dp);
    return dp[i][j];
}

int uniquePathsMemo(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathsMemoHelper(m - 1, n - 1, dp);
}

// TABULATION (Bottom-Up DP)

int uniquePathsTab(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Fill the dp table
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1;       // Start cell
            else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}

