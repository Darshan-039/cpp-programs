// Leetcode 2542. Maximum Subsequence Score


#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // Pair nums1 and nums2 → {nums1[i], nums2[i]}
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }

        // Sort based on nums2 in descending order
        // because nums2 acts as the minimum in score
        sort(vec.begin(), vec.end(), [&](auto &p1, auto &p2) {
            return p1.second > p2.second;
        });

        // Min heap to keep track of k largest nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long Ksum = 0;

        // Take first k elements
        for(int i = 0; i < k; i++) {
            Ksum += vec[i].first;
            pq.push(vec[i].first);
        }

        // Initial result
        long long result = Ksum * vec[k - 1].second;

        // Process remaining elements
        for(int i = k; i < n; i++) {

            // Remove smallest nums1 and add current nums1
            Ksum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);

            // Calculate new score
            result = max(result, Ksum * vec[i].second);
        }

        return result;
    }
};

int main() {
    int n, k;

    cout << "Enter size of arrays: ";
    cin >> n;

    vector<int> nums1(n), nums2(n);

    cout << "Enter nums1: ";
    for(int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter nums2: ";
    for(int i = 0; i < n; i++) cin >> nums2[i];

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    long long result = obj.maxScore(nums1, nums2, k);

    cout << "Maximum Score: " << result << endl;

    return 0;
}