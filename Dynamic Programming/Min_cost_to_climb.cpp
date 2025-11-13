/*
Problem Statement:

You are given an integer array `cost` where cost[i] is the cost of the i-th step.
Once you pay the cost, you can climb either one or two steps.
You can start from either step 0 or step 1.
Return the minimum cost to reach the top of the floor.

Time Complexity: O(n)
Space Complexity: varies (as per approach)
*/

#include <vector>
#include <algorithm>
using namespace std;

/*
MEMOIZATION (Top-Down DP).

Time Complexity: O(n)
Space Complexity: O(n) (recursion + dp array)
*/

int minCostMemoHelper(int i, vector<int>& cost, vector<int>& dp) {
    if (i < 0) return 0;
    if (i == 0 || i == 1) return cost[i];
    if (dp[i] != -1) return dp[i];

    return dp[i] = cost[i] + min(minCostMemoHelper(i - 1, cost, dp),
                                 minCostMemoHelper(i - 2, cost, dp));
}

int minCostClimbingStairsMemo(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n, -1);
    return min(minCostMemoHelper(n - 1, cost, dp),
               minCostMemoHelper(n - 2, cost, dp));
}

/*
TABULATION (Bottom-Up DP)

Time Complexity: O(n)
Space Complexity: O(n)
*/

int minCostClimbingStairsTab(vector<int>& cost) {
    int n = cost.size();
    if (n == 1) return cost[0];

    vector<int> dp(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

/*
SPACE OPTIMIZED TABULATION

Idea:
- Only the previous two values are needed.
- Use two variables instead of dp array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

int minCostClimbingStairsOptimized(vector<int>& cost) {
    int n = cost.size();
    if (n == 1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}
