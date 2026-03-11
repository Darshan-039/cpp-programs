// Leetcode :- 20. Valid Parentheses

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {

            // If opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else { // closing bracket

                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Match type
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '['))
                    return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    bool ans = obj.isValid(s);

    cout << (ans ? "Valid" : "Invalid") << endl;
}
