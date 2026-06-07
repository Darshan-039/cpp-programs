// Leetcode 1320. Minimum Distance to Type a Word Using Two Fingers


// Approach 1 - Recursion + Memoization (Top-Down DP)

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









// Approach 2 - Recursion + Memoization (Top-Down DP) with optimized state representation

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:

    /*
        dp[i][f1][f2]

        i  = current index in word
        f1 = current position of finger 1
        f2 = current position of finger 2

        Stores minimum distance needed
        from index i onwards
    */
    int dp[301][27][27];

    // Convert character position into keyboard coordinates
    pair<int, int> getCoord(int pos) {
        return {pos / 6, pos % 6};
    }

    // Calculate Manhattan Distance
    int getDistance(int pos1, int pos2) {

        auto [x1, y1] = getCoord(pos1);
        auto [x2, y2] = getCoord(pos2);

        return abs(x1 - x2) + abs(y1 - y2);
    }

    // Recursive DP function
    int solve(string &word, int i, int f1, int f2) {

        // If all characters typed
        if(i >= word.length()) {
            return 0;
        }

        // Current character position
        int curr = word[i] - 'A';

        // DP memoization
        if(dp[i][f1][f2] != -1) {
            return dp[i][f1][f2];
        }

        /*
            Case 1:
            Both fingers not used yet
        */
        if(f1 == 26 && f2 == 26) {

            // Start using finger1
            return dp[i][f1][f2] =
                   solve(word, i + 1, curr, f2);
        }

        /*
            Case 2:
            Finger2 not used yet
        */
        if(f2 == 26) {

            // Use finger2 for current character
            int moveF2 =
                solve(word, i + 1, f1, curr);

            // Use finger1 for current character
            int moveF1 =
                getDistance(f1, curr)
                + solve(word, i + 1, curr, f2);

            return dp[i][f1][f2] =
                   min(moveF1, moveF2);
        }

        /*
            Case 3:
            Both fingers already used
        */

        // Move finger1
        int moveF1 =
            getDistance(f1, curr)
            + solve(word, i + 1, curr, f2);

        // Move finger2
        int moveF2 =
            getDistance(f2, curr)
            + solve(word, i + 1, f1, curr);

        // Store minimum answer
        return dp[i][f1][f2] =
               min(moveF1, moveF2);
    }

    int minimumDistance(string word) {

        // Initialize DP with -1
        memset(dp, -1, sizeof(dp));

        // 26 means finger not placed yet
        return solve(word, 0, 26, 26);
    }
};

int main() {

    string word;

    cout << "Enter word: ";
    cin >> word;

    Solution obj;

    cout << "Minimum Distance = "
         << obj.minimumDistance(word);

    return 0;
}

