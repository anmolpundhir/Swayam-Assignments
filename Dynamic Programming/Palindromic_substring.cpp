/*
Problem Statement:

Given a string s, return the **number of palindromic substrings** in it.

A substring is a contiguous sequence of characters within the string.
A palindrome reads the same forward and backward.

Time Complexity:
- Brute Force: O(n³)
- DP: O(n²)
- Expand Around Center: O(n²)

Space Complexity:
- Brute Force: O(1)
- DP: O(n²)
- Expand Around Center: O(1)
*/

#include <string>
#include <vector>
using namespace std;

// BRUTE FORCE APPROACH

bool isPalindrome(string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

int countSubstringsBrute(string s) {
    int n = s.size(), count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j))
                count++;
        }
    }
    return count;
}

// DYNAMIC PROGRAMMING (Bottom-Up)

int countSubstringsDP(string s) {
    int n = s.size(), count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}

// EXPAND AROUND CENTER (Optimized)

int expandAroundCenter(string& s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    return count;
}

int countSubstringsCenter(string s) {
    int n = s.size(), count = 0;
    for (int center = 0; center < n; center++) {
        // Odd length palindromes
        count += expandAroundCenter(s, center, center);
        // Even length palindromes
        count += expandAroundCenter(s, center, center + 1);
    }
    return count;
}
