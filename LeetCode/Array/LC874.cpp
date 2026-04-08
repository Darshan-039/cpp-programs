// Leetcode 874. Walking Robot Simulation


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // Store obstacles in a set for O(1) lookup
        unordered_set<string> st;

        for(vector<int>& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;   // robot's x-coordinate
        int y = 0;   // robot's y-coordinate
        int maxD = 0; // max distance squared

        // Direction vector (initially facing North)
        pair<int, int> dir = {0, 1}; // (dx, dy)

        // Traverse all commands
        for(int i = 0; i < commands.size(); i++) {

            // Turn left (90°)
            if(commands[i] == -2) {
                dir = {-dir.second, dir.first};
            }

            // Turn right (90°)
            else if(commands[i] == -1) {
                dir = {dir.second, -dir.first};
            }

            // Move forward step-by-step
            else { 
                for(int step = 0; step < commands[i]; step++) {

                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    // Create key for obstacle check
                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    // Stop if obstacle is present
                    if(st.find(nextKey) != st.end()) break;

                    // Update position
                    x = newX;
                    y = newY;
                }
            }

            // Update max distance squared
            maxD = max(maxD, x*x + y*y);
        }

        return maxD;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {

    Solution obj;

    // Example 1
    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};

    cout << "Max Distance: " << obj.robotSim(commands, obstacles) << endl;

    // Example 2
    vector<int> commands2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles2 = {{2, 4}};

    cout << "Max Distance: " << obj.robotSim(commands2, obstacles2) << endl;

    return 0;
}