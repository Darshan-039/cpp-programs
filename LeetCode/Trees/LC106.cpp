// Leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal



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
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &index, int inorderStart, int inorderEnd, unordered_map<int,int> &mp) {
        // Base Case
        if(index < 0 || inorderStart > inorderEnd) return NULL; 

        //find element in inorder from preorder
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int position  = mp[element];

        root -> right = solve(inorder, postorder, index, position+1, inorderEnd, mp);
        root -> left = solve(inorder, postorder, index, inorderStart, position-1, mp);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;

        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(inorder, postorder, postOrderIndex, 0, n-1, mp);
    }
};