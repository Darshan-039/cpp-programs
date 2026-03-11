#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class node {
public: 
    int data;
    int i;
    int j;

    node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(node *a, node *b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Push the first element of each array
    for(int i = 0; i < k; i++) {
        if(!kArrays[i].empty()) {
            node* temp = new node(kArrays[i][0], i, 0);
            minHeap.push(temp);
        }
    }

    vector<int> ans;

    while(!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int i = temp->i;
        int j = temp->j;

        // Step 2: If next element exists in the same row, push it
        if(j + 1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
        
        // Clean up memory to avoid leaks
        delete temp; 
    }

    return ans;
}

int main() {
    // Sample Input: 3 sorted arrays
    vector<vector<int>> kArrays = {
        {1, 5, 9},
        {4, 8, 10},
        {2, 6, 12}
    };
    int k = 3;

    vector<int> result = mergeKSortedArrays(kArrays, k);

    // Print the merged array
    cout << "Merged Sorted Array: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}