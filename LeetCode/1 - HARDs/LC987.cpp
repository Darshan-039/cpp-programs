// Leetcode 987. Vertical Order Traversal of a Binary Tree



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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        /** * DATA STRUCTURE EXPLANATION:
         * map<int, ...>  -> Organizes by Horizontal Distance (HD). Automatically sorts left-to-right.
         * map<int, multiset<int>> -> The inner map organizes by Level (row).
         * multiset<int>  -> Handles multiple nodes at the same (HD, Level). 
         * Automatically sorts them by value as required by LeetCode.
         */
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue stores: {Current Node, {Horizontal Distance, Level}}
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;
        if(!root) return ans;

        // Initialize BFS with root at coordinate (0, 0)
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            // Store the node value at its specific (hd, level) coordinate
            nodes[hd][level].insert(frontNode->val);

            // Move left: HD decreases by 1, Level increases by 1
            if(frontNode->left) 
                q.push({frontNode->left, {hd - 1, level + 1}});
            
            // Move right: HD increases by 1, Level increases by 1
            if(frontNode->right) 
                q.push({frontNode->right, {hd + 1, level + 1}});
        }

        /**
         * FLATTENING THE MAP INTO THE RESULT:
         * i.first  = Horizontal Distance (e.g., -1, 0, 1)
         * j.first  = Level (e.g., 0, 1, 2)
         * k        = Individual node values
         */
        for(auto i : nodes) {
            vector<int> col; // Temporary vector for one vertical column
            for(auto j : i.second) {
                // Insert all elements of the multiset (already sorted) into the column
                for(int k : j.second) {
                    col.push_back(k);
                }
            }
            // Push the completed column into the final 2D result
            ans.push_back(col);
        }

        return ans;
    }
};