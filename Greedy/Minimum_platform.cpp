// Problem Statement:
// Given two arrays:
// - 'arr[]' → arrival times of trains.
// - 'dep[]' → departure times of trains.

// You need to find the **minimum number of platforms** required at the
// railway station so that no train has to wait for another to leave.

#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of platforms required
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0;
    int platforms = 0, maxPlatforms = 0;

    // Traverse both arrays using two pointers
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;              // Train arrives → need one more platform
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        } else {
            platforms--;              // Train departs → free one platform
            j++;
        }
    }

    return maxPlatforms;  // Minimum number of platforms required
}
