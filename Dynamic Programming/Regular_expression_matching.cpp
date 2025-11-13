/*
Problem Statement:

Given an input string `s` and a pattern `p`, implement **regular expression matching** 
with support for `'.'` and `'*'` where:
- `'.'` matches any single character.
- `'*'` matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Time Complexity:
- Recursive: O(2^(m+n))
- Memoization / Tabulation: O(m * n)
Space Complexity:
- Recursive: O(m+n)
- Memoization: O(m * n)
- Tabulation: O(m * n)
*/

#include <vector>
#include <string>
using namespace std;

// RECURSIVE APPROACH

bool regexRecursive(string& s, string& p, int i, int j) {
    // Base cases
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;

    // If string exhausted, check if remaining pattern is all '*'
    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k += 2)
            if (p[k + 1] != '*') return false;
        return (j % 2 == 1);
    }

    // If characters match or pattern has '.'
    if (s[i] == p[j] || p[j] == '.')
        return regexRecursive(s, p, i - 1, j - 1);

    // If pattern has '*'
    if (p[j] == '*') {
        bool zeroOccur = regexRecursive(s, p, i, j - 2); // Treat '*' as 0 occurrences
        bool oneOrMoreOccur = false;
        if (p[j - 1] == s[i] || p[j - 1] == '.')
            oneOrMoreOccur = regexRecursive(s, p, i - 1, j); // Consume one char

        return zeroOccur || oneOrMoreOccur;
    }

    return false;
}

// MEMOIZATION (Top-Down DP)

bool regexMemoHelper(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;

    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k += 2)
            if (p[k + 1] != '*') return false;
        return (j % 2 == 1);
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == p[j] || p[j] == '.')
        return dp[i][j] = regexMemoHelper(s, p, i - 1, j - 1, dp);

    if (p[j] == '*') {
        bool zeroOccur = regexMemoHelper(s, p, i, j - 2, dp);
        bool oneOrMoreOccur = false;

        if (p[j - 1] == s[i] || p[j - 1] == '.')
            oneOrMoreOccur = regexMemoHelper(s, p, i - 1, j, dp);

        return dp[i][j] = zeroOccur || oneOrMoreOccur;
    }

    return dp[i][j] = false;
}

bool regexMemo(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return regexMemoHelper(s, p, m - 1, n - 1, dp);
}

// TABULATION (Bottom-Up DP)

bool regexTab(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    // Handle patterns like a*, a*b*, etc.
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*' && j > 1)
            dp[0][j] = dp[0][j - 2];
    }

    // Fill table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') {
                // 0 occurrence
                dp[i][j] = dp[i][j - 2];

                // 1 or more occurrence
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}
