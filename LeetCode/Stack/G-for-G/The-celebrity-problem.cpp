#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rowCheck(vector<vector<int>>& mat, int candidate, int n) {
        for(int i = 0; i < n; i++) {
            if(i != candidate && mat[candidate][i] == 1)
                return false;
        }
        return true;
    }
    
    bool colCheck(vector<vector<int>>& mat, int candidate, int n) {
        for(int i = 0; i < n; i++) {
            if(i != candidate && mat[i][candidate] == 0)
                return false;
        }
        return true;
    }

    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        stack<int> st;
        for(int i = 0; i < n; i++) st.push(i);

        while(st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if(mat[a][b] == 1) st.push(b);
            else st.push(a);
        }

        int candidate = st.top();

        if(rowCheck(mat, candidate, n) && colCheck(mat, candidate, n))
            return candidate;

        return -1;
    }
};

int main() {
    int n;
    cin >> n;   // number of people

    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.celebrity(mat) << endl;

    return 0;
}
