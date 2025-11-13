/*
Problem Statement:

You are a professional robber planning to rob houses arranged in a circle.
Each house has a certain amount of money.
Because the houses are in a circle, the first and last house are adjacent.
You cannot rob two adjacent houses.
Return the maximum amount of money you can rob.
*/

#include <vector>
#include <algorithm>
using namespace std;

/*
Helper function: Linear house robber for indices [start, end]
*/
int robLinearMemoHelper(int i, vector<int>& nums, vector<int>& dp) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    int rob = nums[i] + robLinearMemoHelper(i - 2, nums, dp);
    int skip = robLinearMemoHelper(i - 1, nums, dp);
    return dp[i] = max(rob, skip);
}

/*
MEMOIZATION (Top-Down DP)

Time Complexity: O(n)
Space Complexity: O(n)
*/
int robLinearMemo(vector<int>& nums, int start, int end) {
    int size = end - start + 1;
    vector<int> dp(size, -1);
    // Shift index for recursion to handle start != 0
    auto helper = [&](auto&& self, int i) -> int {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];
        int rob = nums[start + i] + self(self, i - 2);
        int skip = self(self, i - 1);
        return dp[i] = max(rob, skip);
    };
    return helper(helper, size - 1);
}

int rob2Memo(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(robLinearMemo(nums, 0, n - 2), robLinearMemo(nums, 1, n - 1));
}

/*
TABULATION (Bottom-Up DP)

Time Complexity: O(n)
Space Complexity: O(n)
*/
int robLinearTab(vector<int>& nums, int start, int end) {
    int size = end - start + 1;
    if (size == 1) return nums[start];

    vector<int> dp(size, 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);

    for (int i = 2; i < size; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
    }
    return dp[size - 1];
}

int rob2Tab(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(robLinearTab(nums, 0, n - 2), robLinearTab(nums, 1, n - 1));
}

/*
SPACE OPTIMIZED TABULATION

Time Complexity: O(n)
Space Complexity: O(1)
*/
int robLinearOptimized(vector<int>& nums, int start, int end) {
    int size = end - start + 1;
    if (size == 1) return nums[start];

    int prev2 = nums[start];
    int prev1 = max(nums[start], nums[start + 1]);

    for (int i = 2; i < size; i++) {
        int curr = max(prev1, prev2 + nums[start + i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob2Optimized(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    return max(robLinearOptimized(nums, 0, n - 2), robLinearOptimized(nums, 1, n - 1));
}
