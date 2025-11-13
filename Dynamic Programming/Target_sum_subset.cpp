/*
Problem Statement:

Given an array of positive integers `nums` and a target sum `S`, determine 
if there exists a subset of `nums` whose sum equals `S`.

Time Complexity: O(n*S)
Space Complexity: O(n*S)
*/

#include <vector>
using namespace std;

// MEMOIZATION (Top-Down DP)

bool targetSumMemoHelper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (sum == 0) return true;         // sum achieved
    if (i == 0) return nums[0] == sum; // only first element left
    if (dp[i][sum] != -1) return dp[i][sum];

    bool notTake = targetSumMemoHelper(i - 1, sum, nums, dp);
    bool take = false;
    if (nums[i] <= sum) take = targetSumMemoHelper(i - 1, sum - nums[i], nums, dp);

    return dp[i][sum] = take || notTake;
}

bool targetSumMemo(vector<int>& nums, int S) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(S + 1, -1));
    return targetSumMemoHelper(n - 1, S, nums, dp);
}

// TABULATION (Bottom-Up DP)

bool targetSumTab(vector<int>& nums, int S) {
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(S + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true; // sum 0 is always possible
    if (nums[0] <= S) dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int sum = 1; sum <= S; sum++) {
            bool notTake = dp[i - 1][sum];
            bool take = (nums[i] <= sum) ? dp[i - 1][sum - nums[i]] : false;
            dp[i][sum] = take || notTake;
        }
    }

    return dp[n - 1][S];
}

