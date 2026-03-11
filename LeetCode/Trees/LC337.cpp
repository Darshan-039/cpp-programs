// Leetcode 337. House Robber III



/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

/**
 * Definition for a binary tree node.
 */
class Solution {
public:
    // solve returns a pair<int, int>:
    // first  -> Max money if we ROB this current node
    // second -> Max money if we DO NOT ROB this current node
    pair<int, int> solve(TreeNode* root) {
        // Base Case: If the house is empty, we get 0 money either way
        if(!root) return {0,0};

        // Recursive Step: Get results from left and right children
        pair<int,int> left = solve(root -> left);
        pair<int,int> right = solve(root -> right);

        pair<int, int> ans;

        // --- OPTION 1: ROB THIS HOUSE ---
        // If we rob 'root', we CANNOT rob its direct children (left.first and right.first).
        // We must take the "not robbed" values from children (left.second and right.second).
        ans.first = root -> val + left.second + right.second;

        // --- OPTION 2: DO NOT ROB THIS HOUSE ---
        // If we don't rob 'root', we are free to either rob OR not rob the children.
        // We simply take the maximum possible value from each child's own sub-problem.
        ans.second = max(left.first, left.second) + max(right.first, right.second);

        return ans;
    }

    int rob(TreeNode* root) {
        // Get the final pair for the root node
        pair<int, int> ans = solve(root);
        
        // The answer is the better of the two options at the very top
        return max(ans.first, ans.second);
    }
};