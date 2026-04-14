// Leetcode Problem: 295. Find Median from Data Stream



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Helper function to compare sizes of the two heaps
int sigNum(int a, int b) {
    if(a == b) return 0;
    else if(a > b) return 1;
    else return -1;
}

// Logic to balance heaps and update the current median
void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median) {
    switch( sigNum( maxi.size(), mini.size() ) ) {
        
        case 0: // Both heaps have equal size
            if(element > median) {
                mini.push(element);
                median = mini.top();
            }   
            else {
                maxi.push(element);
                median = maxi.top();
            }  
            break; 

        case 1: // Max-heap (left) has more elements
            if(element > median) {
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            else {
                // To keep balance, move top of maxi to mini
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;
        
        case -1: // Min-heap (right) has more elements
            if(element > median) {
                // To keep balance, move top of mini to maxi
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            else {
                maxi.push(element);
                median = (mini.top() + maxi.top()) / 2;
            }
            break;
    }
}

// Function to process a full vector and return a vector of intermediate medians
vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    priority_queue<int> maxi; // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> mini; // Min-heap for the larger half

    int median = 0; // Starting median

    for(int i = 0; i < n; i++) {
        int element = arr[i];
        callMedian(element, maxi, mini, median);
        ans.push_back(median);
    }

    return ans;
}

int main() {
    // --- Manual Input ---
    vector<int> arr = {5, 15, 1, 3};
    int n = arr.size();

    cout << "Input Stream: ";
    for(int x : arr) cout << x << " ";
    cout << "\n--------------------------\n";

    // Call the function
    vector<int> medians = findMedian(arr, n);

    // Display the output
    cout << "Running Medians: ";
    for(int m : medians) {
        cout << m << " ";
    }
    cout << endl;

    /* Dry Run Explanation for {5, 15, 1, 3}:
       1. Push 5:  [5] | []         -> Median 5
       2. Push 15: [5] | [15]       -> Median (5+15)/2 = 10
       3. Push 1:  [1, 5] | [15]    -> Median 5
       4. Push 3:  [1, 3] | [5, 15] -> Median (3+5)/2 = 4
    */

    return 0;
}