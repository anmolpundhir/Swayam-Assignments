/*
Problem Statement:

Given a grid of size m x n with obstacles, find the number of unique paths 
from the top-left corner (0,0) to the bottom-right corner (m-1,n-1). 
You can only move either down or right at any point. 
A cell with 1 is an obstacle, and a cell with 0 is free.

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include <vector>
using namespace std;

// MEMOIZATION (Top-Down DP)

int uniquePaths2MemoHelper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;
    if (obstacleGrid[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = uniquePaths2MemoHelper(i - 1, j, obstacleGrid, dp) + uniquePaths2MemoHelper(i, j - 1, obstacleGrid, dp);
    return dp[i][j];
}

int uniquePaths2Memo(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePaths2MemoHelper(m - 1, n - 1, obstacleGrid, dp);
}

// TABULATION (Bottom-Up DP)

int uniquePaths2Tab(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0; // obstacle
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1; // start
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }

    return dp[m - 1][n - 1];
}
