// Problem Statement:
// You are given an integer array 'arr' of length N representing a permutation 
// of numbers from 0 to N-1.

// You need to split the array into the maximum number of "chunks" such that 
// sorting each chunk individually and concatenating them results in the 
// whole array being sorted.

#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum number of chunks
int maxChunksToSorted(vector<int>& arr) {
    int maxVal = 0, chunks = 0;

    for (int i = 0; i < arr.size(); i++) {
        maxVal = max(maxVal, arr[i]);  // Track maximum so far

        if (maxVal == i) {             // If max equals index → valid chunk
            chunks++;
        }
    }

    return chunks;  // Total chunks possible
}
