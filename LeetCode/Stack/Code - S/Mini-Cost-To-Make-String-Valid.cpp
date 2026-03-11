#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {

    if (str.length() % 2 == 1) return -1;

    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(ch);
        }
    }

    int open = 0;
    int close = 0;

    while (!st.empty()) {
        if (st.top() == '{')
            open++;
        else
            close++;
        st.pop();
    }

    int ans = (open + 1) / 2 + (close + 1) / 2;
    return ans;
}

int main() {
    string str;
    cout << "Enter the bracket string: ";
    cin >> str;

    int result = findMinimumCost(str);

    if (result == -1)
        cout << "Not possible to balance";
    else
        cout << "Minimum cost to balance = " << result;

    return 0;
}
