// Leetcode 1373: Maximum Sum BST in Binary Tree



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <climits>
#include <algorithm>
using namespace std;

struct NodeInfo {
    int maxi;
    int mini;
    bool isBST;
    int sum; // Changed from 'size' to 'sum'
};

class Solution {
public:
    int maxSum = 0; // Global variable to track the highest sum found

    NodeInfo solve(TreeNode* root) {
        // Base Case: Null nodes are BSTs with sum 0
        if (!root) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        NodeInfo currNode;
        
        // BST Validation
        if (left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini) {
            currNode.isBST = true;
            currNode.sum = left.sum + right.sum + root->val;
            currNode.mini = min(root->val, left.mini);
            currNode.maxi = max(root->val, right.maxi);
            
            // Update global maximum sum
            maxSum = max(maxSum, currNode.sum);
        } else {
            // Not a BST
            currNode.isBST = false;
            currNode.sum = 0; // Sum doesn't matter if isBST is false
            // Optional: return boundaries that ensure parents fail BST check
            currNode.mini = INT_MIN; 
            currNode.maxi = INT_MAX;
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0; // Reset for each call
        solve(root);
        return maxSum;
    }
};