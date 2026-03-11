// Leetcode 85. Maximal Rectangle 




#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] >= element) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    } 

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] >= element) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    } 
    
    int largestRectangleArea(vector<int> heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for(int i = 0; i < n; i++) {
            int height = heights[i];

            if(next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            int newArea = height * width;

            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int area = largestRectangleArea(mat[0]);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] != 0)
                    mat[i][j] += mat[i - 1][j];
                else
                    mat[i][j] = 0;
            }
            area = max(area, largestRectangleArea(mat[i]));
        }
        return area;
    }
};

int main() {
    int n, m;
    cin >> n >> m;   // rows and columns

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.maxArea(mat) << endl;

    return 0;
}
