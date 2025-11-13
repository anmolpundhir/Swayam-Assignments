/*
Problem Statement:

You are given `k` eggs and `n` floors.  
Find the **minimum number of attempts** required in the worst case 
to find the highest floor from which an egg can be dropped without breaking.

Rules:

- If an egg breaks from a floor `x`, it will break from all floors above `x`.
- If an egg does not break from floor `x`, it will not break from floors below `x`.

Time Complexity:
- Recursive: O(2^(n))
- Memoization / Tabulation: O(k * n²)
Space Complexity:
- Recursive: O(k + n)
- Memoization: O(k * n)
- Tabulation: O(k * n)
*/

#include <vector>
#include <climits>
using namespace std;

// RECURSIVE APPROACH

int eggDropRecursive(int eggs, int floors) {
    // Base cases
    if (floors == 0 || floors == 1) return floors;
    if (eggs == 1) return floors;

    int minAttempts = INT_MAX;

    // Try dropping from each floor
    for (int k = 1; k <= floors; k++) {
        int breaks = eggDropRecursive(eggs - 1, k - 1); // egg breaks
        int notBreaks = eggDropRecursive(eggs, floors - k); // egg doesn't break
        int worstCase = 1 + max(breaks, notBreaks);
        minAttempts = min(minAttempts, worstCase);
    }
    return minAttempts;
}

// MEMOIZATION (Top-Down DP)

int eggDropMemoHelper(int eggs, int floors, vector<vector<int>>& dp) {
    if (floors == 0 || floors == 1) return floors;
    if (eggs == 1) return floors;
    if (dp[eggs][floors] != -1) return dp[eggs][floors];

    int minAttempts = INT_MAX;

    for (int k = 1; k <= floors; k++) {
        int breaks = eggDropMemoHelper(eggs - 1, k - 1, dp);
        int notBreaks = eggDropMemoHelper(eggs, floors - k, dp);
        int worstCase = 1 + max(breaks, notBreaks);
        minAttempts = min(minAttempts, worstCase);
    }

    return dp[eggs][floors] = minAttempts;
}

int eggDropMemo(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, -1));
    return eggDropMemoHelper(eggs, floors, dp);
}

// TABULATION (Bottom-Up DP)

int eggDropTab(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    // Base cases
    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }

    // Fill table
    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            dp[e][f] = INT_MAX;

            for (int k = 1; k <= f; k++) {
                int worst = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);
                dp[e][f] = min(dp[e][f], worst);
            }
        }
    }

    return dp[eggs][floors];
}

