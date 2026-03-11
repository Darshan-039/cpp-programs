#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        stack<int> st;
        int n = q.size();
        int halfSize = n / 2;
        
        // 1. Push first half into stack: q = [3, 1], st = [2, 4] (top=4)
        for(int i = 0; i < halfSize; i++) {
            st.push(q.front());
            q.pop();
        }
        
        // 2. Push stack back to q: q = [3, 1, 4, 2]
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        
        // 3. Move the original second half to the back: q = [4, 2, 3, 1]
        for(int i = 0; i < halfSize; i++) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        // 4. Push first half to stack again: q = [3, 1], st = [4, 2] (top=2)
        for(int i = 0; i < halfSize; i++) {
            st.push(q.front());
            q.pop();
        }
        
        // 5. Interleave: Pop from stack, then pop and push from q
        // Result q = [2, 3, 4, 1]
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
            
            int val2 = q.front();
            q.pop();
            q.push(val2);
        }
    }
};

int main() {
    Solution sol;
    queue<int> q;

    // Input: 2, 4, 3, 1
    vector<int> input = {2, 4, 3, 1};
    for(int x : input) q.push(x);

    cout << "Original Queue: 2, 4, 3, 1" << endl;

    sol.rearrangeQueue(q);

    cout << "Rearranged Queue: ";
    while(!q.empty()) {
        cout << q.front() << (q.size() > 1 ? ", " : "");
        q.pop();
    }
    cout << endl;

    return 0;
}