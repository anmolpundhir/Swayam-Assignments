/*
Problem Statement:

Given an integer n, return the least number of perfect square numbers
(e.g., 1, 4, 9, 16, ...) that sum up to n.

Time Complexity: O(n * sqrt(n))
Space Complexity: varies (as per approach)
*/

#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*
MEMOIZATION (Top-Down DP)

Time Complexity: O(n * sqrt(n))
Space Complexity: O(n)
*/

int numSquaresMemoHelper(int n, vector<int>& dp) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, 1 + numSquaresMemoHelper(n - i * i, dp));
    }

    return dp[n] = ans;
}

int numSquaresMemo(int n) {
    vector<int> dp(n + 1, -1);
    return numSquaresMemoHelper(n, dp);
}

/*
TABULATION (Bottom-Up DP)

Time Complexity: O(n * sqrt(n))
Space Complexity: O(n)
*/

int numSquaresTab(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }

    return dp[n];
}

