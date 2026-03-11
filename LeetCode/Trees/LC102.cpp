// Leetcode Problem 102: Binary Tree Level Order Traversal



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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int level)
    {
        if(!root) return;
        
        if(ans.size() < level) ans.push_back({});	
        ans[level-1].push_back(root->val);
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        dfs(root, 1);
        return ans;
    }
};











// Method - 2
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> levels;

        if(!root) return ans;
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL) {
                ans.push_back(levels);
                levels.clear();
                if(!q.empty()) q.push(NULL);
            }
            else {
                levels.push_back(temp -> val);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }

        return ans;
    }
};