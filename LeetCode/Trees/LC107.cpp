// Leetcode 107. Binary Tree Level Order Traversal II



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;

        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode* Fnode = q.front();
            q.pop();

            if(!Fnode) {
                result.insert(result.begin(), temp);
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
            else {
                temp.push_back(Fnode -> val);
                if(Fnode -> left) q.push(Fnode -> left);
                if(Fnode -> right) q.push(Fnode -> right);
            }
        }

        return result;
    }
};