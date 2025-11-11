// Problem Statement:
// ------------------
// You are given two integer arrays:
// - g[]: representing the greed factor of each child.
// - s[]: representing the size of each cookie.

// Each child i can be satisfied if they get a cookie j such that s[j] >= g[i].
// Each child can receive at most one cookie, and each cookie can be assigned to only one child.

// Your goal is to maximize the number of satisfied children.

#include <vector>
#include <algorithm>
using namespace std;

// Function to return the maximum number of satisfied children
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());  // Sort greed factors
    sort(s.begin(), s.end());  // Sort cookie sizes

    int i = 0;  // Pointer for children
    int j = 0;  // Pointer for cookies
    int n = g.size(), m = s.size();

    while (i < n && j < m) {
        if (s[j] >= g[i])  // If cookie can satisfy child
            i++;            // Move to next child
        j++;                // Move to next cookie
    }

    return i;  // Number of satisfied children
}
