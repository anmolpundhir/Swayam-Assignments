// Reverse a given singly linked list and return the head of the reversed list
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Iterative approach to reverse the linked list (O(n) time complexity and O(1) space complexity)
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    return prev; // New head of the reversed list
}

// Recursive approach to reverse the linked list (O(n) time complexity and O(n) space complexity due to recursion stack)
Node* reverseLinkedListRecursive(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recur for the rest of the list
    Node* newHead = reverseLinkedListRecursive(head->next);

    // Reverse the current node's pointer
    head->next->next = head;
    head->next = nullptr;

    return newHead; // New head of the reversed list
}