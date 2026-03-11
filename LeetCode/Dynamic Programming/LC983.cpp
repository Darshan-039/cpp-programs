// Leetcode 983. Minimum Cost For Tickets






// Approach - 1 (Top-Down DP with Memoization)

// #include <iostream>
// #include <vector>
// #include <cstring>   // for memset
// #include <algorithm>
// using namespace std;

// class Solution {
// public:

//     int n;          // number of travel days
//     int t[366];     // memoization array (DP cache)

//     int solve(vector<int>& days, vector<int>& costs, int i) {

//         // Base case: all travel days covered
//         if(i >= n)
//             return 0;

//         // If already computed → return stored answer
//         if(t[i] != -1)
//             return t[i];

//         // ---------------- OPTION 1 ----------------
//         // Buy 1-day pass
//         int cost_1 = costs[0] + solve(days, costs, i + 1);

//         // ---------------- OPTION 2 ----------------
//         // Buy 7-day pass
//         int j = i;
//         int max_day = days[i] + 7;   // coverage limit

//         // find next uncovered travel day
//         while(j < n && days[j] < max_day)
//             j++;

//         int cost_7 = costs[1] + solve(days, costs, j);

//         // ---------------- OPTION 3 ----------------
//         // Buy 30-day pass
//         j = i;
//         max_day = days[i] + 30;

//         while(j < n && days[j] < max_day)
//             j++;

//         int cost_30 = costs[2] + solve(days, costs, j);

//         // store and return minimum cost
//         return t[i] = min({cost_1, cost_7, cost_30});
//     }

//     int mincostTickets(vector<int>& days, vector<int>& costs) {

//         n = days.size();

//         // initialize DP array with -1
//         memset(t, -1, sizeof(t));

//         // start from first travel day
//         return solve(days, costs, 0);
//     }
// };

// int main() {

//     vector<int> days  = {1,4,6,7,8,20};
//     vector<int> costs = {2,7,15};

//     Solution obj;

//     int ans = obj.mincostTickets(days, costs);

//     cout << "Minimum Cost = " << ans << endl;

//     return 0;
// }















// Approach - 2 (Bottom-Up DP)

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // store travel days for O(1) lookup
        unordered_set<int> st(days.begin(), days.end());

        // last day we need to consider
        int last_day = days.back();

        // DP array
        // t[i] = min cost to cover travel till day i
        vector<int> t(last_day + 1, 0);

        t[0] = 0;   // no cost before travelling starts

        // iterate through all calendar days
        for(int i = 1; i <= last_day; i++) {

            // If not a travel day → cost remains same
            if(st.find(i) == st.end()) {
                t[i] = t[i - 1];
                continue;
            }

            // Buy 1-day pass
            int day_1_pass =
                costs[0] + t[max(0, i - 1)];

            // Buy 7-day pass
            int day_7_pass =
                costs[1] + t[max(0, i - 7)];

            // Buy 30-day pass
            int day_30_pass =
                costs[2] + t[max(0, i - 30)];

            // choose minimum cost option
            t[i] = min({day_1_pass, day_7_pass, day_30_pass});
        }

        // answer = cost till last travel day
        return t[last_day];
    }
};


// ---------------- MAIN FUNCTION (INPUT ADDED) ----------------

int main() {

    /*
        Example:

        days  = [1,4,6,7,8,20]
        costs = [2,7,15]

        Expected Output = 11
    */

    vector<int> days  = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    Solution obj;

    int result = obj.mincostTickets(days, costs);

    cout << "Minimum Cost = " << result << endl;

    return 0;
}