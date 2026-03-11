// Leetcode 897. Increasing Order Search Tree



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
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &ans) {
        if(!root) return;

        inorder(root -> left, ans);
        ans.push_back(root);
        inorder(root -> right, ans);
    }


    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;

        vector<TreeNode*> ans;
        inorder(root, ans);

        int n = ans.size();
        for(int i = 0; i<n-1; i++) {
            ans[i] -> left = nullptr;
            ans[i] -> right = ans[i+1];
        }

        ans[n-1] -> left = nullptr;
        ans[n-1] -> right = nullptr;

        return ans[0];
    }
};