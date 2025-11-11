// Problem Statement:
// ------------------
// At a lemonade stand, each lemonade costs $5.
// Customers line up and pay with either a $5, $10, or $20 bill.
// You must provide correct change to each customer in order.

// Initially, you have no change.

// Given an integer array 'bills' where bills[i] is the bill the ith customer pays,
// return true if you can provide change to every customer, otherwise false.

#include <vector>
using namespace std;

// Function to check if change can be given to every customer
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            five++;  // Customer pays with $5, no change needed
        } 
        else if (bill == 10) {
            if (five == 0) return false;  // Need one $5 for change
            five--;
            ten++;
        } 
        else { // bill == 20
            if (ten > 0 && five > 0) {  // Prefer one $10 + one $5
                ten--;
                five--;
            } 
            else if (five >= 3) {       // Otherwise, use three $5 bills
                five -= 3;
            } 
            else {
                return false;            // Cannot provide change
            }
        }
    }
    return true;  // All customers served successfully
}
