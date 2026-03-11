// Leetcode Problem 124: Binary Tree Maximum Path Sum



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
    int sum = INT_MIN;

    int calculateMaxPathSum(TreeNode* root) {
        // Base case;
        if(!root) return 0;

        // Recursively calculate leftMax path and Right max Path
        int leftMax = max(0 , calculateMaxPathSum(root -> left));
        int rightMax = max(0 , calculateMaxPathSum(root -> right));

        // Update ans
        sum = max(sum, root -> val + leftMax + rightMax);

        return root -> val + max(leftMax,rightMax);
    }


    int maxPathSum(TreeNode* root) {
        calculateMaxPathSum(root);
        return sum;
    }
};