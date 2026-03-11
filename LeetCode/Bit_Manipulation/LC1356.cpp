// Leetcode 1356: Sort Integers by The Number of 1 Bits




// Approach - 1: Using Map

// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
// using namespace std;
    
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
        
//         // Map: key = number of 1 bits, value = list of numbers
//         map<int, vector<int>> mp;

//         // Step 1: Group numbers by count of 1 bits
//         for(int x : arr) {
//             int bits = __builtin_popcount(x);  // count 1 bits
//             mp[bits].push_back(x);
//         }

//         vector<int> ans;

//         // Step 2: Traverse map (automatically sorted by key)
//         for(auto &p : mp) {
//             vector<int> &v = p.second;

//             // Sort numbers having same bit count
//             sort(v.begin(), v.end());

//             // Add to final answer
//             for(int x : v) {
//                 ans.push_back(x);
//             }
//         }

//         return ans;
//     }
// };

// int main() {

//     // Input array
//     vector<int> arr = {0,1,2,3,4,5,6,7,8};

//     Solution obj;

//     // Call function
//     vector<int> result = obj.sortByBits(arr);

//     // Print result
//     cout << "Sorted array by number of 1 bits:\n";
//     for(int x : result) {
//         cout << x << " ";
//     }

//     return 0;
// }







// Approach - 2: Using Custom Comparator (Lambda Function)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        // Custom comparator (lambda function)
        auto lambda = [&](int &a, int &b) {

            // count number of 1 bits in a and b
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);

            // if both have same number of 1 bits
            // then sort by actual value
            if (countA == countB)
                return a < b;

            // otherwise sort by number of 1 bits
            return countA < countB;
        };

        // sort array using custom comparator
        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};

int main() {

    // Input array
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    Solution obj;

    // Call function
    vector<int> result = obj.sortByBits(arr);

    // Print output
    cout << "Sorted by number of 1 bits:\n";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}