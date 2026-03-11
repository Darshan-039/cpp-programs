// Leetcode 167 :- Two Sum II - Input Array Is Sorted   


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int s = 0;
        int e = numbers.size() - 1;

        while (s < e) {
            int sum = numbers[s] + numbers[e];

            if (sum == target) {
                ans.push_back(s + 1); // 1-based index
                ans.push_back(e + 1);
                break;
            }
            else if (sum > target) {
                e--;
            }
            else {
                s++;
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> result = obj.twoSum(numbers, target);

    cout << "Output indices: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
