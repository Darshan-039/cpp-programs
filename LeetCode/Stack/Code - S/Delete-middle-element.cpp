#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    // Base Case
    if (count == size / 2) {
        inputStack.pop();   // delete middle element
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
    stack<int> st;

    // 🔹 Input in code (stack elements)
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);   // Stack top

    int N = st.size();

    deleteMiddle(st, N);

    // 🔹 Print stack after deleting middle
    cout << "Stack after deleting middle element:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
