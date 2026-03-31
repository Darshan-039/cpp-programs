// Leetcode 1448. Count Good Nodes in Binary Tree



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    // DFS function to traverse the tree
    void dfs(TreeNode* root, int maxi, int &ans) {
        // Base case: if node is NULL
        if (!root) return;

        // Check if current node is a "good node"
        // A node is good if its value is >= max value seen so far
        if (root->val >= maxi) {
            ans++;
        }

        // Update the maximum value seen so far
        maxi = max(maxi, root->val);

        // Recur for left and right subtree
        dfs(root->left, maxi, ans);
        dfs(root->right, maxi, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;

        // Start DFS with root value as initial max
        dfs(root, root->val, ans);

        return ans;
    }
};