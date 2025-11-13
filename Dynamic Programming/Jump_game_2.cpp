/*
Problem Statement:

Given an array of non-negative integers `nums`, where nums[i] represents 
the maximum jump length from that position, return the minimum number of 
jumps to reach the last index. You can assume that you can always reach 
the last index.

Time Complexity:
- O(n^2)

Space Complexity:
- O(n)
*/

#include <vector>
#include <algorithm>
using namespace std;

// MEMOIZATION (Top-Down DP)

int jumpMemoHelper(int i, vector<int>& nums, vector<int>& dp) {
    int n = nums.size();
    if (i >= n - 1) return 0; // reached or beyond last index
    if (dp[i] != -1) return dp[i];

    int minJumps = 1e9;
    int furthestJump = min(i + nums[i], n - 1);
    for (int next = i + 1; next <= furthestJump; next++) {
        minJumps = min(minJumps, 1 + jumpMemoHelper(next, nums, dp));
    }

    return dp[i] = minJumps;
}

int jumpMemo(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return jumpMemoHelper(0, nums, dp);
}

// TABULATION (Bottom-Up DP)

int jumpTab(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1e9);
    dp[n - 1] = 0; // last index requires 0 jumps

    for (int i = n - 2; i >= 0; i--) {
        int furthestJump = min(i + nums[i], n - 1);
        for (int j = i + 1; j <= furthestJump; j++) {
            dp[i] = min(dp[i], 1 + dp[j]);
        }
    }

    return dp[0];
}
