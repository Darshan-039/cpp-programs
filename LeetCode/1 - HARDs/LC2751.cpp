// Leetcode 2751. Robot Collisions



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // Step 1: Store indices [0...n-1]
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Step 2: Sort indices based on positions
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        // Stack to keep track of robots moving RIGHT
        stack<int> st;

        // Step 3: Traverse robots in sorted order of position
        for (int id : idx) {

            // If robot is moving RIGHT → push into stack
            if (directions[id] == 'R') {
                st.push(id);
            } 
            else {
                // Robot moving LEFT → possible collisions
                while (!st.empty() && healths[id] > 0) {

                    int top = st.top(); // last RIGHT-moving robot

                    if (healths[top] < healths[id]) {
                        // RIGHT robot dies
                        st.pop();
                        healths[id] -= 1;
                        healths[top] = 0;
                    } 
                    else if (healths[top] > healths[id]) {
                        // LEFT robot dies
                        healths[top] -= 1;
                        healths[id] = 0;
                        break;
                    } 
                    else {
                        // Both have equal health → both die
                        st.pop();
                        healths[top] = 0;
                        healths[id] = 0;
                        break;
                    }
                }
            }
        }

        // Step 4: Collect surviving robots' healths
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Sample Input
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths   = {10, 10, 15, 12};
    string directions     = "RLRL";

    // Function call
    vector<int> ans = obj.survivedRobotsHealths(positions, healths, directions);

    // Output result
    cout << "Survived Robots Healths: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}