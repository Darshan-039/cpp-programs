// Letcode 2515. Shortest Distance to Target String in a Circular Array


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX; // store minimum distance

        // Traverse all indices
        for(int i = 0; i < n; i++) {

            // If current word matches target
            if(words[i] == target) {

                // Distance when moving right (clockwise)
                int distRight = (i - startIndex + n) % n;

                // Distance when moving left (anti-clockwise)
                int distLeft = (startIndex - i + n) % n;

                // Take minimum of both directions
                ans = min({ans, distRight, distLeft});
            }
        }

        // If target never found
        return ans == INT_MAX ? -1 : ans;
    }
};


int main() {

    Solution obj;

    vector<string> words = {"hello", "i", "am", "coding", "hello"};
    string target = "hello";
    int startIndex = 1;

    int result = obj.closestTarget(words, target, startIndex);

    cout << "Minimum distance: " << result << endl;

    return 0;
}