// Leetcode 2462. Total Cost to Hire K Workers


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        // Min-heaps (priority queues) for left and right candidates
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int i = 0;        // pointer from start
        int j = n - 1;    // pointer from end
        int hired = 0;   // number of workers hired
        long long ans = 0; // total cost

        // Repeat until we hire k workers
        while (hired < k) {

            // Fill left heap with 'candidates' elements
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }

            // Fill right heap with 'candidates' elements
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j]);
                j--;
            }

            // Get minimum from both heaps
            int min_1 = pq1.empty() ? INT_MAX : pq1.top();
            int min_2 = pq2.empty() ? INT_MAX : pq2.top();

            // Choose smaller cost worker
            if (min_1 <= min_2) {
                ans += pq1.top();  // add cost
                pq1.pop();         // remove from heap
            } 
            else {
                ans += pq2.top();
                pq2.pop();
            }

            hired++; // increment hired count
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // 🔹 Sample Input
    vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k = 3;
    int candidates = 4;

    // 🔹 Function Call
    long long result = obj.totalCost(costs, k, candidates);

    // 🔹 Output
    cout << "Total Cost: " << result << endl;

    return 0;
}