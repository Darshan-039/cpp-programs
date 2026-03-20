// Leetcode 1415. The k-th Lexicographical String of All Happy Strings of Length n




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char startWith = 'a';   // starting character (a, b, or c)
    int counter = 0;        // to count valid happy strings

    // Recursive function to generate happy strings
    string solve(int i, int n, string temp, int k) {

        // Add first character (decided beforehand)
        if(i == 1) 
            temp.push_back(startWith);

        // If length reached, check if it's kth string
        if(i >= n) {
            counter++;
            if(counter == k) 
                return temp;
            return "";
        }

        // Try all possible characters
        for(char ch = 'a'; ch <= 'c'; ch++) {

            // Ensure no two adjacent characters are same
            if(ch != temp.back()) {

                temp.push_back(ch);  // choose

                // recursive call
                string ans = solve(i + 1, n, temp, k);
                if(ans != "") 
                    return ans;

                temp.pop_back();     // backtrack
            }
        }

        return "";
    }

    string getHappyString(int n, int k) {

        // Total possible happy strings
        int totalStr = 3 * (1 << (n - 1));

        // If k is larger than total possible strings
        if(totalStr < k) 
            return "";

        // Each starting character group size
        int eachGroupStr = 1 << (n - 1);

        // Decide starting character (a, b, or c)
        while(true) {
            if(k - eachGroupStr > 0) {
                k -= eachGroupStr;
                startWith += 1;
            }
            else break;
        }

        string temp;
        return solve(1, n, temp, k);
    }
};

int main() {
    Solution obj;

    // Sample input
    int n = 3;
    int k = 9;

    // Function call
    string result = obj.getHappyString(n, k);

    // Output
    cout << "Kth Happy String: " << result << endl;

    return 0;
}