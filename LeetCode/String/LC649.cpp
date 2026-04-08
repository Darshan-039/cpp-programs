// Leetcode 649. Dota2 Senate


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
        This function removes (bans) the next available senator
        of opposite party (ch) starting from index idx.
    */
    void removal(string &senate, vector<bool> &removed, int idx, char ch, int n) {

        while (true) {
            // If we find an unremoved senator of target party → ban it
            if (senate[idx] == ch && !removed[idx]) {
                removed[idx] = true;
                break;
            }
            // Move circularly
            idx = (idx + 1) % n;
        }
    }

    /*
        Main logic:
        - Each active senator bans one opponent
        - Continue until one party is fully removed
    */
    string predictPartyVictory(string senate) {
        int n = senate.size();

        // Track removed senators
        vector<bool> removed(n, false);

        // Count number of Radiant (R) and Dire (D)
        int R_count = count(senate.begin(), senate.end(), 'R');
        int D_count = n - R_count;

        int idx = 0;

        // Continue until one party is eliminated
        while (R_count > 0 && D_count > 0) {

            // Skip if current senator is already removed
            if (removed[idx]) {
                idx = (idx + 1) % n;
                continue;
            }

            // If current is Radiant → remove next Dire
            if (senate[idx] == 'R') {
                removal(senate, removed, (idx + 1) % n, 'D', n);
                D_count--;
            }
            // If current is Dire → remove next Radiant
            else {
                removal(senate, removed, (idx + 1) % n, 'R', n);
                R_count--;
            }

            // Move to next senator
            idx = (idx + 1) % n;
        }

        // Return winner
        return R_count == 0 ? "Dire" : "Radiant";
    }
};


int main() {
    string senate;

    cout << "Enter senate string (R/D): ";
    cin >> senate;

    Solution obj;
    string result = obj.predictPartyVictory(senate);

    cout << "Winning Party: " << result << endl;

    return 0;
}