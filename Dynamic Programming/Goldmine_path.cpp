/*
Problem Statement:

Given a grid of size m x n representing a gold mine, where each cell contains
a certain amount of gold, find a path starting from any row in the first column
to the last column that collects the maximum amount of gold.
You can move to the cell diagonally up-right, right, or diagonally down-right.

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


// PATH WITH MAX GOLD - TABULATION

pair<int, vector<pair<int,int>>> goldMinePath(vector<vector<int>>& gold) {
    int m = gold.size();
    int n = gold[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    vector<vector<int>> nextCell(m, vector<int>(n, -1)); // to track path

    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            int right = (j == n - 1) ? 0 : dp[i][j + 1];
            int rightUp = (i == 0 || j == n - 1) ? 0 : dp[i - 1][j + 1];
            int rightDown = (i == m - 1 || j == n - 1) ? 0 : dp[i + 1][j + 1];

            dp[i][j] = gold[i][j];
            if (right >= rightUp && right >= rightDown) {
                dp[i][j] += right;
                nextCell[i][j] = i;       // move straight
            } else if (rightUp >= right && rightUp >= rightDown) {
                dp[i][j] += rightUp;
                nextCell[i][j] = i - 1;   // move right-up
            } else {
                dp[i][j] += rightDown;
                nextCell[i][j] = i + 1;   // move right-down
            }
        }
    }

    // Find starting row with maximum gold
    int maxGold = 0, startRow = 0;
    for (int i = 0; i < m; i++) {
        if (dp[i][0] > maxGold) {
            maxGold = dp[i][0];
            startRow = i;
        }
    }

    // Reconstruct path
    vector<pair<int,int>> path;
    int row = startRow;
    for (int j = 0; j < n; j++) {
        path.push_back({row, j});
        row = nextCell[row][j];
        if (row == -1) break;
    }

    return {maxGold, path};
}
