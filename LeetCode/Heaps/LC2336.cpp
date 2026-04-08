// Leetcode 2336: Smallest Number in Infinite Set


#include <bits/stdc++.h>
using namespace std;




// Approach 1: Using vector<bool>

class SmallestInfiniteSet1 {
public:
    vector<bool> nums; // track available numbers
    int i;             // pointer to current smallest number
    
    SmallestInfiniteSet1() {
        nums = vector<bool>(1001, true); // initially all numbers available
        i = 1;
    }
    
    int popSmallest() {
        int result = i;     // current smallest
        nums[i] = false;    // mark it as removed
        
        // find next smallest available number
        for(int j = i + 1; j < 1001; j++) {
            if(nums[j]) {
                i = j;
                break;
            }
        }
        
        return result;
    }
    
    void addBack(int num) {
        nums[num] = true; // mark as available again
        
        // update pointer if needed
        if(num < i) {
            i = num;
        }
    }
};







// Approach-2 (Using map + priority+queue + a variable to point to smallest num)

class SmallestInfiniteSet {
public:
    
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!pq.empty()) {
            result = pq.top();
            pq.pop();
            st.erase(result);
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end()) return;
        
        st.insert(num);
        pq.push(num);
    }
};


// Approach-3 (Using only ordered_set and a variable to point to smallest num)

class SmallestInfiniteSet {
public:
    set<int> st;
    
    int currSmallest;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!st.empty()) {
            result = *st.begin();
            st.erase(st.begin()); //or, st.erase(result) also works
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
    }
};