// Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal



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
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &index, int inorderStart, int inorderEnd, unordered_map<int,int> &mp) {
        // Base Case
        if(index >= preorder.size() || inorderStart > inorderEnd) return NULL; 

        //find element in inorder from preorder
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int position  = mp[element];

        root -> left = solve(inorder, preorder, index, inorderStart, position-1, mp);
        root -> right = solve(inorder, preorder, index, position+1, inorderEnd, mp);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preOrderIndex = 0;

        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(inorder, preorder, preOrderIndex, 0, n-1, mp);
    }
};