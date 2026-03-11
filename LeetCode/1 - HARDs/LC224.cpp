// Leetcode 224: Basic Calculator



#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;

        long long number = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                number = (number * 10) + (s[i] - '0');
            }
            else if(s[i] == '+') {
                result += (sign * number);
                number = 0;
                sign = 1;
            }
            else if(s[i] == '-') {
                result += (sign * number);
                number = 0;
                sign = -1;
            }
            else if(s[i] == '(') {
                // Save current context to stack
                st.push(result);
                st.push(sign);
                // Reset for expression inside parentheses
                result = 0;
                number = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                result += (sign * number);
                number = 0;

                int st_sign = st.top(); st.pop();
                int last_result = st.top(); st.pop();

                result *= st_sign;
                result += last_result;
            }
        }

        result += (sign * number);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Array of test cases
    vector<string> test_cases = {
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        "2147483647", // Testing large numbers
        "-(2 + 3)"     // Testing unary-like behavior via parentheses
    };

    for (const string& test : test_cases) {
        cout << "Input: \"" << test << "\"" << endl;
        cout << "Output: " << sol.calculate(test) << endl;
        cout << "---------------------------" << endl;
    }

    return 0;
}