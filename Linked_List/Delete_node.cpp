// Delete a node from given position in a singly linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to delete a node at a specific position
void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    // If head needs to be removed
    if (position == 0) {
        head = head->next;
        delete temp;
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != nullptr && i < position - 1; ++i) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    // Node temp->next is the node to be deleted
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
    // No need to return head as we are modifying it directly
    // Time Complexity: O(n) in the worst case
}