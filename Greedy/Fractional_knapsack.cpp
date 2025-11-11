// Problem Statement:
// You are given:
// - 'N' items, each with a value 'val[i]' and weight 'wt[i]'.
// - A knapsack that can carry a maximum weight 'W'.

// You need to maximize the total value in the knapsack by selecting items.
// You can take fractions of items (i.e., it’s not 0/1 knapsack).

#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int value, weight;
};

// Comparator function to sort by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to get maximum total value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);  // Sort by ratio (descending)

    double totalValue = 0.0;

    for (auto& item : items) {
        if (W >= item.weight) {             // Take full item
            W -= item.weight;
            totalValue += item.value;
        } else {                            // Take fractional part
            totalValue += item.value * ((double)W / item.weight);
            break;                          // Knapsack full
        }
    }

    return totalValue;  // Maximum value achievable
}

