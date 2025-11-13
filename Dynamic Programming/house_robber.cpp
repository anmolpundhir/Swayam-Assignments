/*
Problem Statement:

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money.
You cannot rob two adjacent houses.
Return the maximum amount of money you can rob.

Time Complexity: O(n)
Space Complexity: varies with approach
*/

#include <vector>
#include <algorithm>
using namespace std;

/*
MEMOIZATION (Top-Down DP)

Time Complexity: O(n)
Space Complexity: O(n) (dp array + recursion stack)
*/

int robMemoHelper(int i, vector<int>& nums, vector<int>& dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    int rob = nums[i] + robMemoHelper(i - 2, nums, dp);
    int skip = robMemoHelper(i - 1, nums, dp);

    return dp[i] = max(rob, skip);
}

int robMemo(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return robMemoHelper(n - 1, nums, dp);
}

/*
TABULATION (Bottom-Up DP)

Time Complexity: O(n)
Space Complexity: O(n)
*/

int robTab(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

/*
SPACE OPTIMIZED TABULATION

Time Complexity: O(n)
Space Complexity: O(1)
*/

int robOptimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
