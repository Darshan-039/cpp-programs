// Leetcode 113. Path Sum II



#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:

    vector<vector<int>> ans;

    // DFS function to find all paths
    void solve(TreeNode* root, int targetSum, int sum, vector<int> &nums) {
        if(!root) return;

        // Add current node value
        sum += root->val;
        nums.push_back(root->val);

        // If it's a leaf node
        if(!root->left && !root->right) {
            // Check if sum matches target
            if(targetSum == sum) 
                ans.push_back(nums);

            // Backtrack before returning
            nums.pop_back();
            return;
        }

        // Traverse left and right
        solve(root->left, targetSum, sum, nums);
        solve(root->right, targetSum, sum, nums);

        // Backtracking step
        nums.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> nums;
        solve(root, targetSum, 0, nums);
        return ans;
    }
};

int main() {
    Solution obj;

    // Constructing Binary Tree manually
    /*
            5
           / \
          4   8
         /   / \
        11  13  4
       /  \      \
      7    2      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Function Call
    vector<vector<int>> result = obj.pathSum(root, targetSum);

    // Output
    cout << "Paths with sum " << targetSum << ":" << endl;
    for(auto &path : result) {
        for(int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}