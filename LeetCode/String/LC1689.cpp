// Leetcode 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers





// Approach - 1 (Brute Force)

#include <iostream>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int count = 0;

        while (true) {
            bool changed = false;

            for (char &ch : n) {
                if (ch != '0') {
                    ch--;      // subtract 1
                    changed = true;
                }
            }

            if (!changed)
                break;

            count++;
        }

        return count;
    }
};

int main() {
    string n;

    // take input
    cout << "Enter number string: ";
    cin >> n;

    Solution obj;
    cout << "Minimum partitions = " << obj.minPartitions(n);

    return 0;
}













// Approach - 2 (Optimized without modifying the string)
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;

        for (char ch : n) maxDigit = max(maxDigit, ch - '0');

        return maxDigit;
    }
};

int main() {
    string n;

    // take input
    cout << "Enter number string: ";
    cin >> n;

    Solution obj;
    cout << "Minimum partitions = " << obj.minPartitions(n);

    return 0;
}