// Leetcode 3864. Minimum Cost to Partition a Binary String




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;

    // Memoization map to store computed substring results
    unordered_map<string, long long> mp;

    // Prefix array to count number of '1's quickly
    vector<int> prefix;

    // Recursive function to compute minimum cost for substring s[i..j]
    long long solve(string &s, int i, int j, int encCost, int flatCost) {

        int len = j - i + 1;

        // Base case: single character segment
        if(len == 1) {
            if(s[i] == '1') return encCost;   // sensitive element
            else return flatCost;             // non-sensitive element
        }

        // Create substring for memoization key
        string str = s.substr(i, len);

        // If already computed, return stored result
        if(mp.count(str)) return mp[str];

        // Number of '1's in substring using prefix sum
        int ones = prefix[j] - (i == 0 ? 0 : prefix[i-1]);

        // Cost if we do NOT split the segment
        long long dont_split;

        if(ones == 0)
            dont_split = flatCost;
        else
            dont_split = 1LL * len * ones * encCost;

        long long split = LLONG_MAX;

        // If length is even, we can split into two equal halves
        if(len % 2 == 0) {

            int mid = (i + j) / 2;

            long long cost1 = solve(s, i, mid, encCost, flatCost);
            long long cost2 = solve(s, mid + 1, j, encCost, flatCost);

            split = cost1 + cost2;
        }

        // Store and return minimum cost
        return mp[str] = min(dont_split, split);
    }

    long long minCost(string s, int encCost, int flatCost) {

        n = s.length();

        // Resize prefix array
        prefix.resize(n);

        // Build prefix sum for counting '1's
        prefix[0] = (s[0] == '1');

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + (s[i] == '1');

        return solve(s, 0, n-1, encCost, flatCost);
    }
};

int main() {

    Solution obj;

    // Example input
    string s = "10110100";
    int encCost = 2;
    int flatCost = 1;

    cout << obj.minCost(s, encCost, flatCost);

    return 0;
}