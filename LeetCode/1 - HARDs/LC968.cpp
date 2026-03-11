// Leetcode 968. Binary Tree Cameras



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
    int cameras = 0;
    
    int solve(TreeNode* root) {
        // 0 - Not covered
        // 1 - Has a Camera
        // 2 - Is covered (No camera here, but a child has one)

        // Base Case
        // Step - 1 If node is NULL, consider it covered '2'
        // This prevents us from placing unnecessary cameras at the bottom.
        if(!root) return 2;

        // Recursive calls
        int left = solve(root -> left);
        int right = solve(root -> right);

        // if any child is not covered , this node MUST have a camera
        if(left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // 2. If any child has a camera, this node is now covered.
        if(left == 1 || right == 1) return 2; // Now this node 'Is covered'

        // 3. If both children are covered (but don't have cameras), 
        // this node is currently NOT covered and needs its parent to help.
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        // If the root itself is not covered after the recursion,
        // we must place a camera on the root.
        if (solve(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};