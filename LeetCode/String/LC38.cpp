// Leetcode 38. Count and Say



#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // BASE CASE: The sequence always starts with "1" for n = 1
        if(n == 1) return "1";

        // RECURSIVE STEP: Get the string representation of the previous term
        string say = countAndSay(n-1);
        int l = say.length();
        string result = "";

        // ITERATION: Traverse the string to "count and say" digits
        for(int i = 0; i < l; i++) {
            char ch = say[i];
            int count = 1;

            // INNER LOOP: Count identical consecutive digits
            while(i + 1 < l && say[i] == say[i+1]) {
                count++;
                i++;
            }

            // BUILD RESULT: Append count + digit
            result += to_string(count) + string(1, ch);
        } 

        return result;
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter the value of n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        string result = sol.countAndSay(n);
        cout << "The " << n << "-th term is: " << result << endl;
    }
    
    return 0;
}