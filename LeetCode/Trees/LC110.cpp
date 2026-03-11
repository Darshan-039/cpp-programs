// Leetcode 110. Balanced Binary Tree


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
private:
    pair<bool,int> height(TreeNode* root) {
        if(root == NULL) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = height(root -> left);
        pair<bool,int> right = height(root -> right);

        pair<bool,int> ans;
        ans.second = max(left.second,right.second) + 1;
        if( (left.first && right.first) && (abs(left.second - right.second) <= 1) ) {
            ans.first = true;    
        }
        else {
            ans.first = false;
        }

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        // Base case
        return height(root).first;
    }
};