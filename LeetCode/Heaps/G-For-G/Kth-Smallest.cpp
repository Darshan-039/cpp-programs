#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int> pq;
        
        // Push first k elements into the max-heap
        for(int i = 0; i < k; i++) pq.push(arr[i]);
        
        // Process the rest of the elements
        for(int i = k; i < n; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};

int main() {
    // 1. Initialize the Solution object
    Solution sol;

    // 2. Define the input array and k
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    // 3. Call the function and store the result
    int result = sol.kthSmallest(arr, k);

    // 4. Output the result
    cout << "The " << k << "rd smallest element is: " << result << endl;

    return 0;
}