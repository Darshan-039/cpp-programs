// Leetcode :- 1247  Minimum Swaps to Make Strings Equal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt_xy = 0, cnt_yx = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') cnt_xy++;
            else if (s1[i] == 'y' && s2[i] == 'x') cnt_yx++;
        }

        // If total mismatches are odd -> impossible
        if ((cnt_xy + cnt_yx) % 2 == 1) return -1;

        // Each pair of same type gives 1 swap
        // Remaining one of each type gives 2 swaps
        return cnt_xy / 2 + cnt_yx / 2 + (cnt_xy % 2) * 2;
    }
};

int main() {
    string s1, s2;

    cout << "Enter first string (s1): ";
    cin >> s1;

    cout << "Enter second string (s2): ";
    cin >> s2;

    Solution obj;
    int result = obj.minimumSwap(s1, s2);

    cout << "Minimum swaps = " << result << endl;

    return 0;
}
