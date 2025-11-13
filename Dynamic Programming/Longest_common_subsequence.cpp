/*
Problem Statement:

Given two strings text1 and text2, return the length of their 
Longest Common Subsequence (LCS).

A subsequence is a sequence that appears in the same relative order, 
but not necessarily contiguous.

Time Complexity:
- Recursive: O(2^(m+n))
- Memoization / Tabulation: O(m * n)

Space Complexity:
- Recursive: O(m+n)
- Memoization: O(m*n) + recursion stack
- Tabulation: O(m*n)
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// RECURSIVE APPROACH

int lcsRecursive(string& s1, string& s2, int i, int j) {
    // Base case: if either string is exhausted
    if (i == 0 || j == 0) return 0;

    // If characters match
    if (s1[i - 1] == s2[j - 1])
        return 1 + lcsRecursive(s1, s2, i - 1, j - 1);

    // If they don't match, take the max of two possibilities
    return max(lcsRecursive(s1, s2, i - 1, j),
               lcsRecursive(s1, s2, i, j - 1));
}

// MEMOIZATION (Top-Down DP)

int lcsMemoHelper(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + lcsMemoHelper(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = max(lcsMemoHelper(s1, s2, i - 1, j, dp),
                          lcsMemoHelper(s1, s2, i, j - 1, dp));
}

int lcsMemo(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return lcsMemoHelper(s1, s2, m, n, dp);
}

// TABULATION (Bottom-Up DP)

int lcsTab(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
