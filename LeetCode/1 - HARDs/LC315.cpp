// Leetcode :- 315  Count of Smaller Numbers After Self



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Sort in descending order to count smaller elements on the right easily
        mergeSort(v, 0, n - 1, ans);

        return ans;
    }

private:
    void mergeSort(vector<pair<int, int>>& v, int s, int e, vector<int>& ans) {
        if (s >= e) return;

        int mid = s + (e - s) / 2;
        mergeSort(v, s, mid, ans);
        mergeSort(v, mid + 1, e, ans);
        merge(v, s, mid, e, ans);
    }

    void merge(vector<pair<int, int>>& v, int s, int mid, int e, vector<int>& ans) {
        vector<pair<int, int>> temp;
        int i = s;
        int j = mid + 1;

        while (i <= mid && j <= e) {
            // If left element is greater than right element
            if (v[i].first > v[j].first) {
                // All elements from j to e in the right sorted half are smaller than v[i]
                ans[v[i].second] += (e - j + 1);
                temp.push_back(v[i]);   
                i++;
            } else {
                temp.push_back(v[j]);
                j++;
            }
        }

        while (i <= mid) temp.push_back(v[i++]);
        while (j <= e) temp.push_back(v[j++]);

        for (int k = s; k <= e; k++) {
            v[k] = temp[k - s];
        }
    }
};

// --- Main Function to provide input ---
int main() {
    Solution sol;
    
    // Example Input
    vector<int> nums = {5, 2, 6, 1};
    
    vector<int> result = sol.countSmaller(nums);

    // Output the result
    cout << "Input:  [5, 2, 6, 1]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}