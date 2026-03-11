// Leetcode 215: Kth Largest Element in an Array



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Declaration of a Min-Heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Step 1: Push first k elements into the min-heap
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Step 2: For the rest of the elements, if the element is 
        // larger than the top, swap it in.
        for(int i = k; i < n; i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // The top of the min-heap is the kth largest element
        return pq.top();
    }
};

int main() {
    Solution sol;

    // Example Input
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    /* Explanation for this input:
       Sorted: [6, 5, 5, 4, 3, 3, 2, 2, 1]
       The 4th largest is 4.
    */

    int result = sol.findKthLargest(nums, k);

    cout << "Array: ";
    for(int x : nums) cout << x << " ";
    
    cout << "\nThe " << k << "th largest element is: " << result << endl;

    return 0;
}