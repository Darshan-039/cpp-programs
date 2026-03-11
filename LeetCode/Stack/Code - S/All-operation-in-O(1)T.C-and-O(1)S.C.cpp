// Given a stack, implement all the operations like push(), pop(), top(), 
    // and getMin() in O(1) time and O(1) space complexity.


#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    int mini;

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2 * data - mini); // encoded value
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        int curr = s.top();
        s.pop();

        if (curr < mini) {
            // restore previous minimum
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if (s.empty()) return -1;

        int curr = s.top();
        if (curr < mini)
            return mini;
        return curr;
    }

    int getMin() {
        if (s.empty()) return -1;
        return mini;
    }
};

int main() {
    SpecialStack st;

    // 🔹 Input written directly in code
    st.push(5);
    cout << "Min: " << st.getMin() << endl; // 5

    st.push(3);
    cout << "Min: " << st.getMin() << endl; // 3

    st.push(7);
    cout << "Top: " << st.top() << endl;    // 7
    cout << "Min: " << st.getMin() << endl; // 3

    st.push(2);
    cout << "Min: " << st.getMin() << endl; // 2

    st.pop();
    cout << "Min after pop: " << st.getMin() << endl; // 3

    st.pop();
    cout << "Top after pop: " << st.top() << endl;    // 3
    cout << "Min after pop: " << st.getMin() << endl; // 3

    return 0;
}
