#include "SortedLinkedListDict.hpp"

/**
 * Insert an item into a sorted linked list.
 */
void SortedLinkedListDict::insert(int key) {

    Node* temp = new Node;
    Node* curr = head;

    temp->data = key;
    temp->next = nullptr;


    //Empty List
    if(!head || key < head->data) {
        temp->next = head;
        head = temp;
        return;
    }

    // make sure next node is not empty and then compare its data to key
    while(curr->next != nullptr && curr->next->data < key) {
        curr = curr->next; // move the traverse forward
    }

    //Insert the key after current
    temp->next = curr->next;
    curr->next = temp;

}

/**
 * Lookup an item in a sorted linked list.
 */

bool SortedLinkedListDict::lookup(int key) const {

    const Node* curr = head;

    // traverse the list until we find (or skip past: terminate loop)
    while(curr && curr->data <= key) {
        // Check if values match
        if(curr->data == key) {
            return true;
        }
        // if value doesn't match keep going.
        curr = curr->next;
    }
    // Value wasn't found
    return false;
}


/**
 * Remove an item from a sorted linked list.
 */
void SortedLinkedListDict::remove(int key) {

    //Declare a traversing node
    Node* curr = head;


    // Case: Empty List (if head is a null pointer)
    if (!head) {
        return;
    }

    // The first item in the list is the one to remove
    if (head-> data == key) {
        Node* temp = head; // save the current head
        head = head->next; // move head to the next node
        delete temp; // delete the old head
        return;
    }



    //If a next node exist and it doesn't equal what we are trying to insert. Move forward.
    while (curr->next && curr->next->data !=key) {
        curr = curr->next; // move to the next node
    }

    // Remove the key if found if curr next is null that means we didn't find it.
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}


/**
 * CHANGELOG:
 *
 * 1.0
 *  - Attempted while loop to update temp node and current node
 *
 * 2.0
 * Figured out that was dumb, as I needed "temp" to hold the key I needed to insert
 *
 * 3.0
 * for remove, I found myself trying to set temp-> data to key, not ideal, as the first two cases already check if
 * "Key" exists and stops there, we hust need temp to point to the next (as the curr->next-> data is the item we want to delete)
 * we set a temp node to point ot the key we want to delete so we have a reference for it. then move the curr->next to the next node after the one we want to delete.
 * so current node is SAFE and points to the NODE after the next so we don't point to the node we are deleting. Then we delete temp.
 *
 *
 * IF I have time maybe I could create a traversing function?
 *
 *
 *
 *
 * Highly inefficient Insert which require traversing the entire list. every time (potentially)
 * and then doing it for n amount of values im trying to insert. which makes it O(n^2).
 *
 */

