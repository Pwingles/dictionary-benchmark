#include "UnsortedLinkedListDict.hpp"
void UnsortedLinkedListDict::insert(int key) {
    // Node to insert
    Node* newNode = new Node(key);

    // Insert new node at the head.
    newNode->next = head;
    head = newNode;

}
bool UnsortedLinkedListDict::lookup(int key) const {
    Node* curr = head;

    // While current isn't null, check to see if the data it holds matches the key
    while (curr) {
        if (curr->data == key) {
            return true; // return true if data matches key
        }
        // Iterate one forward if no match
        curr = curr->next;
    }
    return false; // return false if we reach the end of the list
}
void UnsortedLinkedListDict::remove(int key) {
    Node* curr = head;
    Node* prev = nullptr;
    // Empty list
    if(!head) {
        return;
    }

    // The first item in the list is the one to remove
    if (head-> data == key) {
        Node* temp = head; // save the current head
        head = head->next; // move head to the next node
        delete temp; // delete the old head
        return;
    }

    // While not at the ened of the list and the data doesn't match the key, move traverse by 1
    while (curr && curr->data != key) {
        prev = curr; // save the previous node
        curr = curr->next; // move to the next node
    }

    // If we found the key, remove it
    if (curr && curr->data == key) {
        prev->next = curr->next;
        delete curr;
    }

}