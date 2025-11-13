/*
Problem Statement:

You are climbing a staircase with 'n' steps.
You can climb either 1 or 2 steps at a time.
Find the total number of distinct ways to reach the top.
*/

#include <vector>
using namespace std;

/*
MEMOIZATION (Top-Down Dynamic Programming)
Time Complexity: O(n)
Space Complexity: O(n)  (DP array + recursion stack)
*/

int climbStairsMemo(int n, vector<int>& dp) {
    if (n <= 2) return n;            // Base cases: 1->1 way, 2->2 ways
    if (dp[n] != -1) return dp[n];   // Return cached value if available
    return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}

/*
TABULATION (Bottom-Up Dynamic Programming)
Time Complexity: O(n)
Space Complexity: O(n)
*/

int climbStairsTab(int n) {
    if (n <= 2) return n;            // Base cases

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    // Fill table iteratively
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*
SPACE OPTIMIZED TABULATION
Time Complexity: O(n)
Space Complexity: O(1)
*/

int climbStairsOptimized(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;

    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
