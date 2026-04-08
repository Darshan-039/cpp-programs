// Leetcode 901. Online Stock Span


#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:

    // Stack stores pair<price, span>
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner() {}

    // Function to calculate span of current price
    int next(int price) {
        int span = 1; // Minimum span is always 1 (today itself)

        // Pop all smaller or equal prices and add their spans
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price with its calculated span
        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner obj;

    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << "Stock spans: ";
    for(int i = 0; i < n; i++) {
        cout << obj.next(prices[i]) << " ";
    }

    return 0;
}