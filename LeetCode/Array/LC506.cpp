#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;




// Approach 1: Using Counting Sort


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        // Find the maximum score
        int maxi = 0;
        for (int x : score)
            maxi = max(maxi, x);

        // temp[score] stores (original index + 1)
        // 0 means the score is not present
        vector<int> temp(maxi + 1, 0);

        // Store the original position of every score
        for (int i = 0; i < n; i++) {
            temp[score[i]] = i + 1;
        }

        vector<string> ans(n);
        int rank = 1;

        // Start from the highest score and assign ranks
        for (int s = maxi; s >= 0; s--) {

            // Skip if this score doesn't exist
            if (temp[s] == 0)
                continue;

            // Get the original index of this score
            int originalIndex = temp[s] - 1;

            // Assign medals to the top three athletes
            if (rank == 1)
                ans[originalIndex] = "Gold Medal";
            else if (rank == 2)
                ans[originalIndex] = "Silver Medal";
            else if (rank == 3)
                ans[originalIndex] = "Bronze Medal";
            else
                ans[originalIndex] = to_string(rank);

            rank++;
        }

        return ans;
    }
};

int main() {
    // Sample Input
    vector<int> score = {10, 3, 8, 9, 4};

    Solution obj;
    vector<string> ans = obj.findRelativeRanks(score);

    // Print Output
    cout << "Output: ";
    for (string &x : ans)
        cout << x << " ";

    return 0;
}

/*
Input:
score = [10, 3, 8, 9, 4]

Output:
Gold Medal 5 Bronze Medal Silver Medal 4
*/










// Approach 2: Using HashMap and Sorting

vector<string> findRelativeRankss(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> mp;

        // 1. Store original indices
        for(int i = 0; i < n; i++) mp[score[i]] = i;

        // 2. Sort in DESCENDING order (Highest score first)
        sort(score.begin(), score.end(), greater<int>());

        // 3. Assign Ranks
        for(int i = 0; i < n; i++) {
            if(i == 0) ans[mp[score[i]]] = "Gold Medal";
            else if(i == 1) ans[mp[score[i]]] = "Silver Medal";
            else if(i == 2) ans[mp[score[i]]] = "Bronze Medal";
            else ans[mp[score[i]]] = to_string(i + 1);
        }

        return ans;
    }