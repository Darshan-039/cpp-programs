// Leetcode 632. Smallest Range Covering Elements from K Lists



#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Your Node class
class node {
    public:
        int data, row, col;
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
};

// Your Compare class
class compare {
    public:
        bool operator() (node* a, node* b) {
            return a -> data > b -> data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;
        int k = nums.size();

        // 1. Initial Processing: Push first element of each list
        for(int i = 0; i < k; i++) {
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        // 2. Process elements
        while(!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();

            mini = temp -> data;

            // Update range if a smaller one is found
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // Check if next element exists in the same row
            if(temp -> col + 1 < nums[temp -> row].size()) {
                int nextVal = nums[temp -> row][temp -> col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, temp -> row, temp -> col + 1));
            }
            else {
                delete temp; // Clean up memory for the last node
                break; 
            }
            
            delete temp; // Clean up memory after processing
        }

        return {start, end};
    }
};

int main() {
    Solution sol;

    // --- Input 1 ---
    // List 0: [4, 10, 15, 24, 26]
    // List 1: [0, 9, 12, 20]
    // List 2: [5, 18, 22, 30]
    vector<vector<int>> input1 = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result1 = sol.smallestRange(input1);
    cout << "Test Case 1 Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    // Expected: [20, 24]

    // --- Input 2 ---
    vector<vector<int>> input2 = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };

    vector<int> result2 = sol.smallestRange(input2);
    cout << "Test Case 2 Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
    // Expected: [1, 1]

    return 0;
}