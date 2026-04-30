// Leetcode 146. LRU Cache


#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:

    // Doubly linked list to store keys (Most Recently Used at front)
    list<int> dll;

    // Map: key -> {iterator to dll, value}
    map<int, pair<list<int>::iterator, int>> cache;

    int capacity;

    // Constructor
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Move accessed key to front (mark as most recently used)
    void makeMostRecentlyUsed(int key) {
        // Remove from current position
        dll.erase(cache[key].first);

        // Insert at front
        dll.push_front(key);

        // Update iterator in map
        cache[key].first = dll.begin();
    }

    // Get value of key
    int get(int key) {
        // If key not present
        if(!cache.count(key)) return -1;

        // Move key to front (MRU)
        makeMostRecentlyUsed(key);

        return cache[key].second;
    }

    // Insert or update key-value
    void put(int key, int value) {

        // If key already exists
        if(cache.count(key)) {
            cache[key].second = value; // update value
            makeMostRecentlyUsed(key); // move to front
        }
        else {
            // Insert new key at front
            dll.push_front(key);
            cache[key] = {dll.begin(), value};

            capacity--; // reduce available capacity
        }

        // If capacity exceeded, remove LRU (last element)
        if(capacity < 0) {
            int lruKey = dll.back(); // least recently used key

            cache.erase(lruKey); // remove from map
            dll.pop_back();      // remove from list

            capacity++; // restore capacity
        }
    }
};



// ------------------ MAIN FUNCTION ------------------
int main() {

    // Create LRU Cache with capacity = 2
    LRUCache cache(2);

    // Operations
    cache.put(1, 10); // cache = {1=10}
    cache.put(2, 20); // cache = {2=20, 1=10}

    cout << cache.get(1) << endl; // Output: 10 (makes 1 MRU)
    // cache = {1=10, 2=20}

    cache.put(3, 30); 
    // capacity exceeded → remove LRU (key=2)
    // cache = {3=30, 1=10}

    cout << cache.get(2) << endl; // Output: -1 (removed)

    cache.put(4, 40);
    // remove LRU (key=1)
    // cache = {4=40, 3=30}

    cout << cache.get(1) << endl; // Output: -1
    cout << cache.get(3) << endl; // Output: 30
    cout << cache.get(4) << endl; // Output: 40

    return 0;
}