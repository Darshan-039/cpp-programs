#include <bits/stdc++.h> 
using namespace std;

class NStack {
public: 
    int N, S, freespot;
    int *arr, *top, *next;

    // Initialize your data structure.
    NStack(int N, int S) {
        this->N = N;
        this->S = S;

        top = new int[N];
        for(int i = 0; i < N; i++) top[i] = -1;

        next = new int[S];
        for(int i = 0; i < S; i++) {
            next[i] = i + 1;
        }
        next[S - 1] = -1;

        arr = new int[S];
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack.
    bool push(int x, int m) {
        if(freespot == -1) return false;

        int index = freespot;

        freespot = next[index];

        arr[index] = x;

        next[index] = top[m - 1];

        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack.
    int pop(int m) {
        if(top[m - 1] == -1) return -1;

        int index = top[m - 1];
        
        top[m - 1] = next[index];

        next[index] = freespot;
        
        freespot = index;

        return arr[index];
    }
};

int main() {
    // Example: 3 Stacks in an array of size 6
    int n = 3, s = 6;
    NStack st(n, s);

    // Push elements into different stacks
    cout << "Pushing 10 into Stack 1: " << (st.push(10, 1) ? "Success" : "Fail") << endl;
    cout << "Pushing 20 into Stack 1: " << (st.push(20, 1) ? "Success" : "Fail") << endl;
    cout << "Pushing 30 into Stack 2: " << (st.push(30, 2) ? "Success" : "Fail") << endl;

    // Pop elements
    cout << "Popped from Stack 1: " << st.pop(1) << endl; // Should be 20
    cout << "Popped from Stack 2: " << st.pop(2) << endl; // Should be 30
    cout << "Popped from Stack 1: " << st.pop(1) << endl; // Should be 10
    cout << "Popped from Stack 1 (Empty): " << st.pop(1) << endl; // Should be -1

    return 0;
}