#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    void reverseQueue(queue<int> &q) {
        // Method 1: Using stack
        stack<int> s;
        
        // Push all elements of queue into stack
        while(!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        
        // Pop all elements from stack and push back into queue
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }





        // Method - 2 :- Using Recursion
        // if(q.empty()) return;
        
        // int num = q.front();
        // q.pop();
        
        // reverseQueue(q);
        
        // q.push(num);
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // --- INPUT SECTION ---
    // Adding elements to the queue: 4, 3, 1, 10, 2, 6
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    cout << "Original Queue: ";
    queue<int> temp = q; // Copy for printing
    while(!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // --- EXECUTION ---
    sol.reverseQueue(q);

    // --- OUTPUT SECTION ---
    cout << "Reversed Queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
        
        