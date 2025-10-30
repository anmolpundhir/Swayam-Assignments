// Count the number of nodes in a singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to count the number of nodes in the linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head; // Start from the head node
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
    // Time Complexity: O(n)
}