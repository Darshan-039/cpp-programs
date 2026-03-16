// Leetcode 1415. The k-th Lexicographical String of All Happy Strings of Length n



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char startWith = 'a';   // Stores the starting character of the happy string
    int counter = 0;        // Counts how many valid happy strings we generated

    // Recursive function to generate happy strings
    string solve(int i, int n, string temp, int k) {

        // If we are at the first position, push the starting character
        if(i == 1) temp.push_back(startWith);

        // If we reached length n, we formed a happy string
        if(i >= n) {
            counter++;

            // If this is the k-th happy string, return it
            if(counter == k) return temp;

            // Otherwise return empty and continue searching
            return "";
        }

        // Try characters 'a', 'b', 'c'
        for(char ch = 'a'; ch <= 'c'; ch++) {

            // Ensure adjacent characters are not equal
            if(ch != temp.back()) {

                // Choose the character
                temp.push_back(ch);

                // Recurse for next position
                string ans = solve(i+1, n, temp, k);

                // If we found the k-th string, return immediately
                if(ans != "") return ans;

                // Backtrack
                temp.pop_back();
            }
        }

        // If no valid result found
        return "";
    }

    string getHappyString(int n, int k) {

        // Total happy strings = 3 * 2^(n-1)
        int totalStr = 3 * (1 << (n - 1));

        // If k is larger than total possible strings, return empty
        if(totalStr < k) return "";

        // Each starting character group size
        int eachGroupStr = 1 << (n-1);

        // Determine which starting character group contains the k-th string
        while(true) {
            if(k - eachGroupStr > 0) {
                k -= eachGroupStr;
                startWith += 1;  // Move from 'a' → 'b' → 'c'
            }
            else break;
        }

        string temp;

        // Start recursion
        return solve(1, n, temp, k);
    }
};

int main() {

    int n, k;

    // Input
    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;

    string result = obj.getHappyString(n, k);

    // Output
    if(result == "")
        cout << "No such happy string exists\n";
    else
        cout << "Kth Happy String: " << result << endl;

    return 0;
}