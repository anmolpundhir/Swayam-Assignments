// Problem Statement:
// You are given an integer array 'arr' (may contain duplicates).
// You need to split the array into the **maximum number of chunks** 
// such that sorting each chunk individually and concatenating them 
// results in the whole array being sorted.

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to find max chunks when array can contain duplicates
int maxChunksToSorted(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> freq;
    int chunks = 0;

    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;          // Add from original array
        if (freq[arr[i]] == 0) freq.erase(arr[i]);

        freq[sortedArr[i]]--;    // Remove from sorted array
        if (freq[sortedArr[i]] == 0) freq.erase(sortedArr[i]);

        if (freq.empty()) {      // If frequencies match → one chunk possible
            chunks++;
        }
    }
    return chunks;
}
