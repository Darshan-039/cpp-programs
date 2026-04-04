// Leetcode 841. Keys and Rooms



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_set<int> R_numbers; // stores visited room numbers
        vector<bool> visited(n, false); // track visited rooms

        queue<int> q;

        // 🔹 Start from room 0
        q.push(0);
        visited[0] = true;

        // 🔹 BFS traversal
        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int top = q.front();
                q.pop();

                // Mark room as visited
                R_numbers.insert(top);

                // 🔑 Explore keys in current room
                for(int x : rooms[top]) {
                    if(!visited[x] && x < n) {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }

        // 🔹 Check if all rooms are visited
        for(int i = 0; i < n; i++) {
            if(R_numbers.count(i) == 0) 
                return false;
        }

        return true;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    /*
        rooms[i] contains keys of rooms accessible from room i

        Example:
        Room 0 → key to room 1
        Room 1 → key to room 2
        Room 2 → key to room 3
        Room 3 → no keys
    */

    vector<vector<int>> rooms = {
        {1},    // room 0
        {2},    // room 1
        {3},    // room 2
        {}      // room 3
    };

    bool ans = obj.canVisitAllRooms(rooms);

    if(ans) cout << "All rooms can be visited\n";
    else cout << "Cannot visit all rooms\n";

    return 0;
}