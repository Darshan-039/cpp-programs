// Leetcode 3666. Minimum Operations to Make All Characters One





// Approach - 1 - BFS

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     int minOperations(string s, int k) {

//         int n = s.length();

//         // Count number of zeros initially
//         int startZeros = 0;
//         for (char &ch : s) {
//             if (ch == '0')
//                 startZeros++;
//         }

//         // Already all ones
//         if (startZeros == 0)
//             return 0;

//         /*
//             operations[z] =
//             minimum operations needed to reach state
//             having 'z' zeros
//         */
//         vector<int> operations(n + 1, -1);

//         // BFS queue storing current zero counts
//         queue<int> q;
//         q.push(startZeros);
//         operations[startZeros] = 0;

//         // BFS traversal
//         while (!q.empty()) {

//             int z = q.front();
//             q.pop();

//             /*
//                 f = number of zeros chosen to flip
//                 Constraints:
//                 - cannot flip more zeros than available
//                 - must choose exactly k indices
//             */

//             int minF = max(0, k - (n - z));
//             int maxF = min(k, z);

//             for (int f = minF; f <= maxF; f++) {

//                 /*
//                     After flip:
//                     f zeros -> ones
//                     (k - f) ones -> zeros

//                     new zeros =
//                     z - f + (k - f)
//                     = z + k - 2f
//                 */
//                 int newZ = z + k - 2 * f;

//                 if (operations[newZ] == -1) {
//                     operations[newZ] = operations[z] + 1;

//                     // reached all ones
//                     if (newZ == 0)
//                         return operations[newZ];

//                     q.push(newZ);
//                 }
//             }
//         }

//         // impossible case
//         return -1;
//     }
// };

// int main() {
//     string s;
//     int k;

//     cout << "Enter binary string: ";
//     cin >> s;

//     cout << "Enter k: ";
//     cin >> k;

//     Solution obj;
//     cout << "Minimum operations = "
//          << obj.minOperations(s, k) << endl;

//     return 0;
// }














// Approach - 2 - Optimized BFS using sets to efficiently find reachable states in range

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {

        // Length of the binary string
        int n = s.length();

        // Count initial number of zeros in string
        int startZeros = 0;
        for(char &ch: s) 
            if(ch == '0') startZeros++;

        // If already all ones → no operation needed
        if(startZeros == 0) return 0;

        /*
            operations[i] =
            minimum operations required to reach
            a state having exactly i zeros.

            -1 means not visited yet.
        */
        vector<int> operations(n+1, -1);

        /*
            We maintain two sets:
            evenSet → stores counts having even parity
            oddSet  → stores counts having odd parity

            Why?
            Because number of zeros changes with fixed parity
            depending on operation constraints.
        */
        set<int> evenSet;
        set<int> oddSet;

        // Insert all possible zero counts (0 → n)
        for(int count = 0; count <= n; count++) {
            if(count % 2 == 0) evenSet.insert(count);
            else oddSet.insert(count);
        }

        // BFS queue (states = number of zeros)
        queue<int> q;
        q.push(startZeros);

        // Starting state requires 0 operations
        operations[startZeros] = 0;

        // Remove starting state from corresponding set
        if(startZeros % 2 == 0) evenSet.erase(startZeros);
        else oddSet.erase(startZeros);

        /*
            BFS over number of zeros.
            Each state represents how many zeros exist currently.
        */
        while(!q.empty()) {

            int z = q.front();   // current zero count
            q.pop();

            /*
                After flipping any subarray of size k,
                number of zeros can change.

                These formulas compute the minimum and
                maximum possible new zero counts.
            */

            // Minimum possible zeros after operation
            int min_new_z = z + k - 2*min(k, z);

            // Maximum possible zeros after operation
            int max_new_z = z + k - 2*max(0, k-n+z);

            /*
                Only numbers with correct parity are reachable.
                Choose evenSet or oddSet accordingly.
            */
            set<int> &currSet =
                (min_new_z % 2 == 0) ? evenSet : oddSet;

            // Find first candidate ≥ minimum bound
            auto it = currSet.lower_bound(min_new_z);

            /*
                Iterate through all reachable zero counts
                within valid range [min_new_z, max_new_z]
            */
            while(it != currSet.end() && *it <= max_new_z) {

                int newZ = *it;

                // If not visited before
                if(operations[newZ] == -1) {

                    // Distance = previous operations + 1
                    operations[newZ] = operations[z] + 1;

                    // If we reach 0 zeros → answer found
                    if(newZ == 0)
                        return operations[newZ];

                    // Push new state into BFS
                    q.push(newZ);
                }

                /*
                    Remove visited element from set
                    to avoid revisiting and keep complexity low.
                */
                it = currSet.erase(it);
            }
        } 

        // If impossible to reach all ones
        return -1;
    }
};

// ================= MAIN FUNCTION =================
int main() {

    string s;
    int k;

    // Input
    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    // Solution object
    Solution obj;

    // Function call
    int result = obj.minOperations(s, k);

    // Output
    cout << "Minimum Operations = " << result << endl;

    return 0;
}