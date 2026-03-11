#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        
        // Deques to store indices of max and min elements
        deque<int> maxi;
        deque<int> mini;
    
        // Addition of first k size window
        for(int i=0; i<k; i++) {
    
            // Remove smaller elements for maxi
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
    
            // Remove larger elements for mini
            while(!mini.empty() && arr[mini.back()] >= arr[i])
                mini.pop_back();
    
            // push current index
            maxi.push_back(i);
            mini.push_back(i);
        }
        
        // Calculating sum of max and min for first window
        int ans = arr[maxi.front()] + arr[mini.front()];
        res.push_back(ans);
        
        // Processing rest of the elements
        for(int i=k; i<n; i++) {
            
            // Out of window removal
            while(!maxi.empty() && i - maxi.front() >= k) {
                maxi.pop_front();
            }
    
            while(!mini.empty() && i - mini.front() >= k) {
                mini.pop_front();
            }
    
            // addition of new element
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
    
            while(!mini.empty() && arr[mini.back()] >= arr[i])
                mini.pop_back();
    
            maxi.push_back(i);
            mini.push_back(i);    
    
            // Updating ans with sum of max and min
            ans = arr[maxi.front()] + arr[mini.front()];
            res.push_back(ans);
        }
        
        // returning result vector
        return res;
    }
};

int main() {
    // Creating object of Solution class
    Solution s;

    // input array
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    // window size
    int k = 4;

    // calling function
    vector<int> result = s.maxOfSubarrays(arr, k);

    // Printing the result
    cout << "Sum of (Max + Min) for each window: " << endl;
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}