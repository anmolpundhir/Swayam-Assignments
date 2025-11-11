// Problem Statement:
// Given an integer array 'nums' of 2n integers, 
// your task is to group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn)
// such that the sum of min(ai, bi) for all i is maximized.

// Return the maximum possible sum.

#include <vector>
#include <algorithm>
using namespace std;

// Function to return the maximum sum of min pairs
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Sort the array

    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2)
        sum += nums[i];  // Add the smaller element of each pair

    return sum;  // Return maximum possible sum
}
