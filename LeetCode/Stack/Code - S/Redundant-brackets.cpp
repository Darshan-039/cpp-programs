#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if (ch == ')') {
            bool isredundant = true;

            while (st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isredundant = false;
                }
                st.pop();
            }

            if (isredundant) return true;
            st.pop(); // pop '('
        }
    }
    return false;
}

int main()
{
    string s;
    cout << "Enter expression: ";
    cin >> s;

    if (findRedundantBrackets(s))
        cout << "Redundant brackets found";
    else
        cout << "No redundant brackets";

    return 0;
}
