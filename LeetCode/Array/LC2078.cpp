// Leetcode 2078. Two Furthest Houses With Different Colors


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int ans = INT_MIN;  // stores maximum distance

        for(int i = 0; i < n; i++) {

            // Compare with first element
            // If colors are different, update distance (i - 0)
            if(colors[i] != colors[0]) {
                ans = max(ans, i);
            }

            // Compare with last element
            // If colors are different, update distance (n-1 - i)
            if(colors[i] != colors[n - 1]) {
                ans = max(ans, n - 1 - i);
            }
        }

        return ans;
    }
};


// Main function to take input
int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> colors(n);
    cout << "Enter colors: ";
    for(int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    Solution obj;
    int result = obj.maxDistance(colors);

    cout << "Maximum distance between different colors: " << result << endl;

    return 0;
}