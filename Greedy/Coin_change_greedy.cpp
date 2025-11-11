// Problem Statement:
// You are given an amount 'V' and an array 'coins[]' representing 
// denominations of available coins (like Indian currency: 1, 2, 5, 10, 20, 50, 100, 500, 2000).

// Your task is to find the **minimum number of coins/notes** required 
// to make the amount 'V' using a greedy approach.

#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of coins needed

vector<int> minCoins(vector<int>& coins, int V) {
    vector<int> result;

    // Sort in descending order
    sort(coins.rbegin(), coins.rend());

    for (int coin : coins) {
        while (V >= coin) {
            V -= coin;              // Use this coin
            result.push_back(coin); // Add coin to result
        }
    }

    return result; // Contains coins used to make up the amount
}
