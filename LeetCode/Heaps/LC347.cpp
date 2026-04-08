// Leetcode 347. Top K Frequent Elements


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 🔹 Step 1: Count frequency of each number
        unordered_map<int, int> mp;
        for(int x : nums) {
            mp[x]++;
        }

        // 🔹 Step 2: Min Heap (stores {frequency, number})
        // Smallest frequency stays at top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for(auto &[num, freq] : mp) {

            pq.push({freq, num}); // insert into heap

            // 🔹 Keep only top k elements in heap
            if(pq.size() > k) {
                pq.pop(); // remove smallest frequency
            }
        }

        // 🔹 Step 3: Extract elements from heap
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second); // store number
            pq.pop();
        }

        return ans; // contains k most frequent elements
    }
};

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    vector<int> result = obj.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}