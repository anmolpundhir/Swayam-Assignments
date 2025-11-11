// Problem Statement:
// You are given two arrays:
// - 'start[]' → starting times of activities.
// - 'end[]' → ending times of activities.
// Each activity takes place between start[i] and end[i].

// You need to select the maximum number of activities that can be
// performed by a single person, assuming that a person can work
// on only one activity at a time.

#include <vector>
#include <algorithm>
using namespace std;

// Function to find maximum number of activities
int activitySelection(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<pair<int, int>> activities;

    // Pair up start and end times
    for (int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }
    // Sort activities by end time
    sort(activities.begin(), activities.end());

    int count = 1;                      // First activity always selected
    int lastEnd = activities[0].first;  // Track end time of last selected activity

    // Iterate through remaining activities
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastEnd) {
            count++;                    // Select this activity
            lastEnd = activities[i].first;
        }
    }

    return count;  // Maximum number of non-overlapping activities
}
