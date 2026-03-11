// Leetcode 129. Sum Root to Leaf Numbers



class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }

private:
    int solve(TreeNode* node, int currentSum) {
        if (!node) return 0;

        // Calculate the number formed so far
        currentSum = currentSum * 10 + node->val;

        // If it's a leaf node, return the current path sum
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Return the sum of numbers from left and right subtrees
        return solve(node->left, currentSum) + solve(node->right, currentSum);
    }
};