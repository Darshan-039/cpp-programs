#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to maintain the max-heap property
    void heapify(vector<int> &ans, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && ans[largest] < ans[left]) largest = left;
        if (right < n && ans[largest] < ans[right]) largest = right;
        
        if (largest != i) {
            swap(ans[largest], ans[i]);
            heapify(ans, n, largest);
        }
    }

    // Function to merge two max-heaps
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        
        // Step 1: Combine both vectors into one
        for (auto i : a) ans.push_back(i);
        for (auto i : b) ans.push_back(i);
        
        int size = ans.size();
        
        // Step 2: Build the heap starting from the last non-leaf node
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(ans, size, i);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;

    // Input data
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size();
    int m = b.size();

    // Call the function
    vector<int> result = sol.mergeHeaps(a, b, n, m);

    // Output the merged max-heap
    cout << "Merged Max-Heap: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}