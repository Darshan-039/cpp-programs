// Leetcode 875. Koko Eating Bananas


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to check if Koko can eat all bananas at speed = givenHour
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;  // total hours needed
        
        for(int &x : piles) {
            // Add hours required for current pile
            actualHour += x / givenHour;
            
            // If there is a remainder, add one more hour
            if(x % givenHour != 0)
                actualHour++;
        }
        
        // Return true if total hours is within limit
        return actualHour <= h;
    }
    
    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // Search space: speed ranges from 1 to max pile
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        // Binary search
        while(l < r) {
            int mid = l + (r - l) / 2;
            
            if(canEatAll(piles, mid, h)) {
                // Try smaller speed
                r = mid;
            } else {
                // Increase speed
                l = mid + 1;
            }
        }
        
        // Minimum valid speed
        return l;
    }
};

int main() {
    Solution obj;
    
    // Sample input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    
    int result = obj.minEatingSpeed(piles, h);
    
    cout << "Minimum Eating Speed: " << result << endl;
    
    return 0;
}