// Leetcode :- 155 - Min Stack
// Implement a stack that supports push, pop, top, and retrieving the minimum element in constant time.


#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {}

    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2LL * data - mini);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        long long curr = s.top();
        s.pop();

        if (curr < mini) {
            mini = 2 * mini - curr;
        }
    }

    int top() {
        if (s.empty()) return -1;

        long long curr = s.top();
        return (curr < mini) ? mini : curr;
    }

    int getMin() {
        if (s.empty()) return -1;
        return mini;
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: " << st.top() << endl;      // 2
    cout << "Min: " << st.getMin() << endl;  // 2

    st.pop();

    cout << "Top: " << st.top() << endl;      // 7
    cout << "Min: " << st.getMin() << endl;  // 3

    return 0;
}
