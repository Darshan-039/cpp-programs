

// Approach - 1  Brute Force Approach

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional> // For std::greater

// using namespace std;

// int getKthLargest(vector<int> &arr, int k) {
//     vector<int> sums;
//     int n = arr.size();

//     // Generate all subarray sums
//     for(int i = 0; i < n; i++) {
//         int sum = 0;
//         for(int j = i; j < n; j++) {
//             sum += arr[j];
//             sums.push_back(sum);
//         }
//     }

//     // Sort in descending order
//     sort(sums.begin(), sums.end(), greater<int>());

//     // Return the k-th element (1-based index)
//     return sums[k - 1];
// }

// int main() {
//     // Sample Input
//     vector<int> arr = {3, -2, 5};
//     int k = 3;

//     int result = getKthLargest(arr, k);

//     cout << "The " << k << "-th largest subarray sum is: " << result << endl;

//     return 0;
// } 











// Approach - 2 Using Min-Heap (Priority Queue)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getKthLargest(vector<int> &arr, int k) {
    int n = arr.size();
    // Min-heap to keep track of the top k largest sums
    priority_queue<int, vector<int>, greater<int>> mini;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(mini.size() < k) {
                mini.push(sum);
            } else {
                if(sum > mini.top()) {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main() {
    // Test Case: Array [3, -2, 5], k = 3
    // Subarray sums: 3, 1, 6, -2, 3, 5
    // Sorted descending: 6, 5, 3, 3, 1, -2
    // 3rd largest: 3
    vector<int> arr = {3, -2, 5};
    int k = 3;

    cout << "K-th Largest Subarray Sum: " << getKthLargest(arr, k) << endl;

    return 0;
}