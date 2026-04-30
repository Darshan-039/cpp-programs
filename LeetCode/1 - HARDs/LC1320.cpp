// Leetcode 1320. Minimum Distance to Type a Word Using Two Fingers


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    // DP table:
    // t[i][x1][y1][x2][y2]
    // i  -> current index in word
    // x1,y1 -> position of finger 1
    // x2,y2 -> position of finger 2
    int t[301][7][7][7][7];

    // Convert character to keyboard coordinates
    pair<int, int> getCoordinates(char ch) {
        int curr = ch - 'A';
        return {curr / 6, curr % 6};
    }

    // Manhattan distance between two points
    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    // Recursive DP function
    int solve(string &word, int i, int x1, int y1, int x2, int y2) {
        // Base case: all characters typed
        if (i >= word.size()) {
            return 0;
        }

        // Return already computed state
        if (t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1) {
            return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];
        }

        // Get coordinates of current character
        auto [x, y] = getCoordinates(word[i]);

        // Case 1: Both fingers unused initially
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
            return solve(word, i + 1, x, y, x2, y2);
        }

        // Case 2: Second finger unused
        if (x2 == -1 && y2 == -1) {
            // Move second finger to current character
            int moveF2 = solve(word, i + 1, x1, y1, x, y);

            // Move first finger
            int moveF1 = getDistance(x1, y1, x, y) +
                         solve(word, i + 1, x, y, x2, y2);

            return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] =
                   min(moveF1, moveF2);
        }

        // Case 3: Both fingers already used
        int moveF1 = getDistance(x1, y1, x, y) +
                     solve(word, i + 1, x, y, x2, y2);

        int moveF2 = getDistance(x2, y2, x, y) +
                     solve(word, i + 1, x1, y1, x, y);

        // Store minimum result
        return t[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] =
               min(moveF1, moveF2);
    }

    int minimumDistance(string word) {
        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Start recursion with both fingers unused
        return solve(word, 0, -1, -1, -1, -1);
    }
};

int main() {
    string word;

    // Input word
    cout << "Enter uppercase word: ";
    cin >> word;

    Solution obj;

    // Output minimum distance
    cout << "Minimum typing distance: "
         << obj.minimumDistance(word) << endl;

    return 0;
}