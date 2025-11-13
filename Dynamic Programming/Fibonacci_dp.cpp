/*
Problem Statement:
------------------
Given an integer n, find the nth Fibonacci number.

The Fibonacci sequence is defined as:
F(0) = 0, F(1) = 1
For n > 1, F(n) = F(n - 1) + F(n - 2)
*/

#include <iostream>
#include <vector>
using namespace std;

/*
RECURSIVE APPROACH (Brute Force)

Idea:
- Directly use the definition: F(n) = F(n-1) + F(n-2)
- Recomputes same subproblems multiple times → very slow.

Time Complexity: O(2^n)
Space Complexity: O(n) (recursion stack)
*/
int fibRecursive(int n) {
    if (n <= 1) return n; // Base cases
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

/*
MEMOIZATION (Top-Down Dynamic Programming)

Idea:
- Store (memoize) the results of already computed subproblems.
- Avoids recomputation by using a DP array.
- Recursive but efficient.

Time Complexity: O(n)
Space Complexity: O(n) (DP array + recursion stack)
*/
int fibMemoization(int n, vector<int>& dp) {
    if (n <= 1) return n; // Base cases

    if (dp[n] != -1) return dp[n]; // If already computed, return

    // Store and return result
    return dp[n] = fibMemoization(n - 1, dp) + fibMemoization(n - 2, dp);
}

/*
TABULATION (Bottom-Up Dynamic Programming)

Idea:
- Build the solution iteratively from base cases up to n.
- No recursion, so more space-efficient.
- Can be further optimized to use only two variables.

Time Complexity: O(n)
Space Complexity: O(n)
*/

int fibTabulation(int n) {
    if (n <= 1) return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    // Build up the table iteratively
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*
SPACE OPTIMIZED TABULATION

Idea:
- We only need the last two Fibonacci numbers at each step.
- Keep two variables instead of a DP array.

Time Complexity: O(n)
Space Complexity: O(1)
*/
int fibOptimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0, prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

