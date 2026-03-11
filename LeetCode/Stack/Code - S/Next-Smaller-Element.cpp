#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);   // acts as default when no smaller element exists

    for(int i = n - 1; i >= 0; i--) {
        int element = arr[i];

        while(st.top() >= element) {
            st.pop();
        }

        arr[i] = st.top();
        st.push(element);
    }

    return arr;
}

int main() {
    int n;
    cin >> n;              // input size

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];     // input elements
    }

    vector<int> result = nextSmallerElement(arr, n);

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";   // output
    }

    return 0;
}
