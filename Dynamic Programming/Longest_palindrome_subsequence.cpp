/*
Problem Statement:

Given a string s, find the **length of the longest palindromic subsequence** in it.

A subsequence is a sequence derived from another string by deleting some or no characters 
without changing the order of the remaining characters.
Bottom-Up DP)

Time Complexity:
- Recursive: O(2^n)
- Memoization / Tabulation: O(n²)

Space Complexity:
- Recursive: O(n)
- Memoization: O(n²)
- Tabulation: O(n²)
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// RECURSIVE APPROACH

int lpsRecursive(string& s, int i, int j) {
    // Base case
    if (i > j) return 0;
    if (i == j) return 1;

    // If characters match
    if (s[i] == s[j])
        return 2 + lpsRecursive(s, i + 1, j - 1);

    // If not, exclude one char from either side
    return max(lpsRecursive(s, i + 1, j),
               lpsRecursive(s, i, j - 1));
}

// MEMOIZATION (Top-Down DP)

int lpsMemoHelper(string& s, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = 2 + lpsMemoHelper(s, i + 1, j - 1, dp);

    return dp[i][j] = max(lpsMemoHelper(s, i + 1, j, dp),
                          lpsMemoHelper(s, i, j - 1, dp));
}

int lpsMemo(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return lpsMemoHelper(s, 0, n - 1, dp);
}

// TABULATION (Bottom-Up DP)

int lpsTab(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: single characters are palindromic subsequences of length 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Fill table from bottom to top (reversed order for i)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}
