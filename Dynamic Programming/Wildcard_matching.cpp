/*
Problem Statement:

You are given two strings: `s` (the input string) and `p` (the pattern).  
Implement wildcard pattern matching with support for `'?'` and `'*'`:

- `'?'` matches any **single** character.
- `'*'` matches any **sequence** of characters (including the empty sequence).

Return `true` if the pattern `p` matches the entire string `s`.

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

bool wildcardRecursive(string& s, string& p, int i, int j) {
    // Base cases
    if (i < 0 && j < 0) return true;               // Both exhausted
    if (j < 0 && i >= 0) return false;             // Pattern finished, string left
    if (i < 0 && j >= 0) {                         // String empty but pattern may have '*'
        for (int k = 0; k <= j; k++)
            if (p[k] != '*') return false;
        return true;
    }

    // Match case
    if (p[j] == s[i] || p[j] == '?')
        return wildcardRecursive(s, p, i - 1, j - 1);

    // '*' can match empty or one/more characters
    if (p[j] == '*')
        return wildcardRecursive(s, p, i - 1, j) || wildcardRecursive(s, p, i, j - 1);

    return false;
}

// MEMOIZATION (Top-Down DP)

bool wildcardMemoHelper(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0 && i >= 0) return false;
    if (i < 0 && j >= 0) {
        for (int k = 0; k <= j; k++)
            if (p[k] != '*') return false;
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (p[j] == s[i] || p[j] == '?')
        return dp[i][j] = wildcardMemoHelper(s, p, i - 1, j - 1, dp);

    if (p[j] == '*')
        return dp[i][j] = wildcardMemoHelper(s, p, i - 1, j, dp) ||
                          wildcardMemoHelper(s, p, i, j - 1, dp);

    return dp[i][j] = false;
}

bool wildcardMemo(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return wildcardMemoHelper(s, p, m - 1, n - 1, dp);
}

// TABULATION (Bottom-Up DP)

bool wildcardTab(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;  // Empty string matches empty pattern

    // Initialize first row (string empty)
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[m][n];
}
