#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        // Store (value, weight) pairs
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {val[i], wt[i]};
        }

        // Sort items based on value/weight ratio (descending)
        auto cmp = [](pair<int, int> &p1, pair<int, int> &p2) {
            return (1.0 * p1.first / p1.second) > (1.0 * p2.first / p2.second);
        };

        sort(vec.begin(), vec.end(), cmp);

        double ans = 0.0;

        // Traverse sorted items
        for (int i = 0; i < n; i++) {

            // If whole item can be taken
            if (vec[i].second <= capacity) {
                ans += vec[i].first;
                capacity -= vec[i].second;
            } 
            else {
                // Take fractional part of the item
                ans += (1.0 * vec[i].first / vec[i].second) * capacity;
                break;  // knapsack is full
            }
        }

        return ans;
    }
};


// Main function
int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    Solution obj;
    double result = obj.fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value in knapsack: " << result << endl;

    return 0;
}