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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case: we found the insertion point
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // // Recursive steps
        // if (val < root->val) {
        //     root->left = insertIntoBST(root->left, val);
        // } else {
        //     root->right = insertIntoBST(root->right, val);
        // }

        // return root;



        // Iterative method
        TreeNode* curr = root;
        while (true) {
            if (val < curr->val) {
                if (curr->left) curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            } else {
                if (curr->right) curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};