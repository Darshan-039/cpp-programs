// Leetcode 84 :- Largest Rectangle in Histogram


#include <iostream>
#include <climits>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> st;
    st.push(-1);
    
    vector<int> ans(n);
    
    for(int i = n-1; i>=0; i--) {
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
    
    for(int i = 0; i<n; i++) {
        int element = arr[i];
        
        while(st.top() != -1 && arr[st.top()] >= element) {
            st.pop();
        }
        
        ans[i] = st.top();
        st.push(i);
    }
    
    return ans;
}
int main() {
    vector<int> arr = {2,1,5,6,2,3};
    
    int n = 6;
    
    vector<int> next(n);
    next = nextSmallerElement(arr,n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(arr,n);
    
    int area = INT_MIN;
    
    for(int i = 0; i<n; i++) {
        int height = arr[i];
        
        if(next[i] == -1) {
            next[i] = n;
        }

        int width = next[i] - prev[i] - 1;
        
        int newArea = height * width;
        
        area = max(area,newArea);
    }
    
    cout << area;
}