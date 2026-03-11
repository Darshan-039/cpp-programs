#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    // Passing by reference (&q) is more efficient to avoid copying large queues
    queue<int> reverseFirstK(queue<int> &q, int k) {
        // Edge case handling
        if (q.empty() || k > q.size() || k <= 0) {
            return q;
        }
        
        stack<int> s;
        
        // 1. Move first k elements from queue to stack
        for(int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }
        
        // 2. Push them back to queue (now they are at the back in reversed order)
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        // 3. Move the remaining (size - k) elements from front to back
        int t = q.size() - k;
        while(t > 0) {
            int val = q.front();
            q.pop();
            q.push(val);
            t--;
        }
        
        return q;
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // --- INPUT SECTION ---
    // Example: Queue = [1, 2, 3, 4, 5], k = 3
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;

    cout << "Original Queue: 1 2 3 4 5" << endl;
    cout << "Reversing first " << k << " elements..." << endl;

    // --- EXECUTION ---
    queue<int> result = sol.reverseFirstK(q, k);

    // --- OUTPUT SECTION ---
    // Expected Output: 3 2 1 4 5
    cout << "Modified Queue: ";
    while(!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}