/*
Problem Statement:

Given a grid of size m x n filled with non-negative numbers, find a path 
from the top-left corner (0,0) to the bottom-right corner (m-1,n-1) 
which minimizes the sum of all numbers along its path. You can only move 
either down or right at any point.

Time Complexity: O(m*n)
Space Complexity: varies with approach
*/

#include <vector>
#include <algorithm>
using namespace std;

// MEMOIZATION (Top-Down DP)

int minPathSumMemoHelper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 1e9; // out of bounds, return large number
    if (i == 0 && j == 0) return grid[0][0]; // start cell
    if (dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + minPathSumMemoHelper(i - 1, j, grid, dp);
    int left = grid[i][j] + minPathSumMemoHelper(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minPathSumMemo(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return minPathSumMemoHelper(m - 1, n - 1, grid, dp);
}

// TABULATION (Bottom-Up DP)

int minPathSumTab(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = (i > 0) ? dp[i - 1][j] : 1e9;
                int left = (j > 0) ? dp[i][j - 1] : 1e9;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

