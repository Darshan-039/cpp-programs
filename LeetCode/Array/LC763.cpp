// Leetcode 763. Partition Labels


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        // Step 1: Store last occurrence index of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int start = 0; // start index of current partition
        int end = 0;   // farthest last occurrence in current partition

        // Step 2: Traverse string to form partitions
        for (int i = 0; i < s.size(); i++) {
            // Update partition end
            end = max(end, last[s[i] - 'a']);

            // If current index reaches partition end
            if (i == end) {
                // Store partition length
                ans.push_back(end - start + 1);

                // Move start for next partition
                start = end + 1;
            }
        }

        return ans;
    }
};

int main() {
    string s;

    // Input string
    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    // Get partition lengths
    vector<int> result = obj.partitionLabels(s);

    // Output result
    cout << "Partition lengths: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}