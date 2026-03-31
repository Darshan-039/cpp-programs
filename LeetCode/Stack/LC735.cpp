// Leetcode 735. Asteroid Collision



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // acts like a stack

        for (int a : asteroids) {
            bool destroyed = false;

            // Check collision only when:
            // current asteroid is moving left (negative)
            // and stack top is moving right (positive)
            while (!st.empty() && a < 0 && st.back() > 0) {

                // Case 1: current asteroid is bigger → destroy stack top
                if (abs(a) > st.back()) {
                    st.pop_back();
                } 
                // Case 2: both are equal → both destroyed
                else if (abs(a) == st.back()) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                // Case 3: stack top is bigger → current destroyed
                else {
                    destroyed = true;
                    break;
                }
            }

            // If current asteroid is not destroyed, push into stack
            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;
    vector<int> result = obj.asteroidCollision(asteroids);

    cout << "Final state after collisions: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}