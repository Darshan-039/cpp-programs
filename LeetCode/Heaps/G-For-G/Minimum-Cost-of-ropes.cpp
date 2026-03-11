#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& arr) {
        // Create a min-heap to always get the two smallest elements
        priority_queue<int, vector<int>, greater<int>> pq;
        int cost = 0;
        
        // Push all elements into the min-heap
        for(int i : arr) pq.push(i);
        
        // While more than one rope remains
        while(pq.size() > 1) {
            // Pick the smallest rope
            int a = pq.top();
            pq.pop();
            
            // Pick the second smallest rope
            int b = pq.top();
            pq.pop();
            
            // The cost to connect them
            int sum = a + b;
            cost += sum;
            
            // Push the new combined rope back into the heap
            pq.push(sum);
        }
        
        return cost;
    }
};

int main() {
    Solution sol;

    // Example Input: Lengths of ropes
    vector<int> arr = {4, 3, 2, 6};

    // Calculation:
    // 1. Pick 2 and 3 (Cost = 5). Ropes: {4, 6, 5}
    // 2. Pick 4 and 5 (Cost = 9). Ropes: {6, 9}
    // 3. Pick 6 and 9 (Cost = 15). Ropes: {15}
    // Total Cost: 5 + 9 + 15 = 29
    
    int result = sol.minCost(arr);

    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}