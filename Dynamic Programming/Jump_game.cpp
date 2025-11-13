/*
Problem Statement:

Given an array of non-negative integers `nums`, where nums[i] represents 
the maximum jump length from that position, determine if you can reach 
the last index starting from the first index.

Time Complexity: O(n^2) for naive DP, O(n) for greedy optimized
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

// MEMOIZATION (Top-Down DP)

bool canJumpMemoHelper(int i, vector<int>& nums, vector<int>& dp) {
    int n = nums.size();
    if (i >= n - 1) return true;  // reached or beyond last index
    if (dp[i] != -1) return dp[i];

    int furthestJump = min(i + nums[i], n - 1);
    for (int next = i + 1; next <= furthestJump; next++) {
        if (canJumpMemoHelper(next, nums, dp)) return dp[i] = true;
    }

    return dp[i] = false;
}

bool canJumpMemo(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return canJumpMemoHelper(0, nums, dp);
}

// TABULATION (Bottom-Up DP)

bool canJumpTab(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);
    dp[n - 1] = true; // last index can reach itself

    for (int i = n - 2; i >= 0; i--) {
        int furthestJump = min(i + nums[i], n - 1);
        for (int j = i + 1; j <= furthestJump; j++) {
            if (dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}
