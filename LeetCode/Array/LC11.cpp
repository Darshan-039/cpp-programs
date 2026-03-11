// Leetcode:- 11 Container With Most Water

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;               
        int e = height.size() - 1;

        int ans = 0;                

        while (s < e) {

            // Height of container is limited by the smaller building
            int mini = min(height[s], height[e]);

            // Width of container = distance between pointers
            int dist = e - s;

            // Update maximum area
            ans = max(ans, mini * dist);

            // Move the pointer pointing to the smaller height
            // Only increasing the smaller height can improve area
            if (height[s] < height[e]) {
                s++;                 
            }
            else if (height[s] > height[e]) {
                e--;          
            }
            else {
                s++;
                e--;
            }
        }

        return ans;                 
    }
};

int main() {
    // ⭐ Input inside code
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Heights: ";
    for(int x : height) cout << x << " ";
    cout << endl;

    Solution obj;
    int result = obj.maxArea(height);

    cout << "Maximum Area = " << result << endl;

    return 0;
}
