#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    if (stack.empty() || stack.top() < num) {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }

    int n = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack, n);
}

int main() {
    stack<int> st;

    // 🔹 Input in code
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);   // Top of stack

    cout << "Original Stack (top to bottom):\n";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(st);

    cout << "Sorted Stack (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
