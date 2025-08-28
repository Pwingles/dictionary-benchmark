#include "SortedVectorDict.hpp"

/**
 * Insert an item into a sorted vector
 * using binary search.
 * @param key The key to insert.
 */
void SortedVectorDict::insert(int key) {
    std::size_t pos = findPosition(key);

    // Insert key at found positon and shift other elements after it to the right
    data.insert(data.begin() + pos, key);
}

/**
 * Lookup an item in a sorted vector
 * using binary search.
 *
 * @param key The key to look up.
 * @return true if the key is found, false otherwise.
 */
bool SortedVectorDict::lookup(int key) const {

    std::size_t pos = findPosition(key);

    // If it's not the "last element" and the element at that position is the key, we found it.
    return(pos < data.size() && data[pos] == key);
}



/**
 * Remove an item from a sorted vector.
 * @param key The key to remove.
 */
void SortedVectorDict::remove(int key) {
    size_t pos = findPosition(key);

    // If the position is valid and the key matches, erase it.
    if(pos < data.size() && data[pos] == key) {
        data.erase(data.begin() + pos);
    }
}





/**
 * Binary search helper function to find the position of a key.
 * @param key The key to find.
 * @return The index of the key if found, otherwise data.size().
 */
std::size_t SortedVectorDict::findPosition(int key) const {
    std::size_t left = 0, right = data.size();
    while (left < right) {
        std::size_t mid = (left + right) / 2;
        if (data[mid] == key) {
            return mid; // Key found
        }
        else if (data[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}


/**
 * ChangeLog:
 *
 * 1.0:
 * Obvious needed to use binary search for both insert and lookup.
 * Insert uses std::vector::insert to insert the key at the found position.
 * (apparently I am looking for a positon and not an index value) which gave me trouble
 * // FIX was to use data.begin() + left to get the correct iterator. Unable to use data[left] as that would overwrite the value at that index.
 *
 * 2.0
 * every function seems to use the exact same binary search code. Maybe make a helper function?
 *
 * 3.0
 * implemented helpers for binary search.
 *
 * When doing lookup I got out of bound errors because the same issue with position vs index.
 * When my binary search ends, left is the position where the key would be inserted at the end of the vector which is out of bounds (since we not inserting)
 * so I need to check if left is less than data.size() before checking if data[left] == key.
 *
 *
 */