/*
Problem Statement:

Given a string s, return the **longest palindromic substring** in s.
A palindrome is a string that reads the same backward as forward.


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

/*
BRUTE FORCE APPROACH
Generate all substrings and check if each is a palindrome.
*/

bool isPalindrome(string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

string longestPalindromeBrute(string s) {
    int n = s.size();
    int maxLen = 1;
    string ans = s.substr(0, 1);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j) && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
                ans = s.substr(i, maxLen);
            }
        }
    }
    return ans;
}

/*
DYNAMIC PROGRAMMING (Bottom-Up)
dp[i][j] = true if substring s[i..j] is a palindrome
*/
string longestPalindromeDP(string s) {
    int n = s.size();
    if (n <= 1) return s;

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, maxLen = 1;

    // Single characters are palindromes
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // Check substrings of length >= 2
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

/*
EXPAND AROUND CENTER (Optimized)
Expand around each character (and each gap between characters)
*/
string expandFromCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindromeCenter(string s) {
    if (s.empty()) return "";

    string longest = "";
    for (int i = 0; i < s.size(); i++) {
        // Odd length palindrome
        string odd = expandFromCenter(s, i, i);
        // Even length palindrome
        string even = expandFromCenter(s, i, i + 1);

        // Update longest palindrome
        if (odd.size() > longest.size()) longest = odd;
        if (even.size() > longest.size()) longest = even;
    }

    return longest;
}
