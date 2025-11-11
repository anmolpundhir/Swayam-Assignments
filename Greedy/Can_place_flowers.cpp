// Problem Statement:
// You have a long flowerbed represented by an integer array 'flowerbed'
// containing 0s and 1s, where:
// - 0 means the plot is empty.
// - 1 means the plot already has a flower.

// You cannot plant flowers in adjacent plots.

// Given an integer n, return true if n new flowers can be planted in the
// flowerbed without violating the no-adjacent-flowers rule.

#include <vector>
using namespace std;

// Function to determine if n flowers can be planted

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();

    for (int i = 0; i < size && n > 0; i++) {
        if (flowerbed[i] == 0) {
            // Check left and right neighbors
            bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
            bool emptyRight = (i == size - 1 || flowerbed[i + 1] == 0);

            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1;  // Plant flower
                n--;               // One less to plant
            }
        }
    }

    return n == 0;  // True if all flowers placed
}
