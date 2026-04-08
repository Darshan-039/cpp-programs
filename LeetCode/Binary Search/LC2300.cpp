// Leetcode 2300. Successful Pairs of Spells and Potions


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔍 Binary Search:
    // Find the first index in potions such that:
    // potions[mid] * spell >= success
    int search(int sp, vector<int> &potions, long long success, int m) {
        int s = 0;
        int e = m - 1;
        int idx = -1; // store valid index

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if current pair is successful
            if ((long long)potions[mid] * sp >= success) {
                idx = mid;      // valid index found
                e = mid - 1;    // try to find smaller index (left side)
            } 
            else {
                s = mid + 1;    // move right
            }
        }

        return idx; // first valid index or -1 if none found
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        // 🔹 Sort potions for binary search
        sort(potions.begin(), potions.end());

        vector<int> ans;

        // 🔹 For each spell, find number of valid potions
        for (int i = 0; i < n; i++) {
            int idx = search(spells[i], potions, success, m);

            // If no valid index found → 0 pairs
            if (idx == -1) ans.push_back(0);
            else ans.push_back(m - idx); // count of valid potions
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    // 🔹 Function Call
    vector<int> result = obj.successfulPairs(spells, potions, success);

    // 🔹 Output
    cout << "Successful Pairs: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}