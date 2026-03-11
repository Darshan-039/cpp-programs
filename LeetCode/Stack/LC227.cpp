// LeetCode 227: Basic Calculator II




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {

        int n = s.length();

        int number = 0;        // To build the current number (can be multiple digits)
        char lastOp = '+';     // Stores the last operator seen
        vector<int> stack;     // Stack to handle operator precedence

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            // If character is digit, build the number
            if(isdigit(ch)) {
                number = (number * 10) + (ch - '0');
            }

            // If character is operator OR we reached last character
            if((!isdigit(ch) && !isspace(ch)) || i == n-1) {

                // If last operator was '+'
                if(lastOp == '+') {
                    stack.push_back(number);
                }

                // If last operator was '-'
                else if(lastOp == '-') {
                    stack.push_back(-number);
                }

                // If last operator was '*'
                else if(lastOp == '*') {
                    int top = stack.back();
                    stack.pop_back();
                    stack.push_back(top * number);
                }

                // If last operator was '/'
                else if(lastOp == '/') {
                    int top = stack.back();
                    stack.pop_back();
                    stack.push_back(top / number);
                }

                // Reset number for next calculation
                number = 0;

                // Update last operator
                lastOp = ch;
            }
        }

        // Sum all values in stack
        int result = 0;
        for(int x : stack) {
            result += x;
        }

        return result;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter expression: ";
    getline(cin, s);  // Input example: 3+2*2

    int ans = obj.calculate(s);

    cout << "Result = " << ans << endl;

    return 0;
}