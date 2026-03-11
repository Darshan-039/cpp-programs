// Leetcode 98. Validate Binary Search Tree



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
    // Change min and max to long long to handle INT_MIN/MAX edge cases
    bool solve(TreeNode* root, long long min, long long max) {
        if(!root) return true;

        if(root->val > min && root->val < max) {
            // Recurse with updated boundaries
            bool left = solve(root->left, min, root->val);
            bool right = solve(root->right, root->val, max);
            return left && right;
        }
        else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        // Use long long constants that are outside the 32-bit int range
        return solve(root, -2147483649LL, 2147483648LL);
    }
};