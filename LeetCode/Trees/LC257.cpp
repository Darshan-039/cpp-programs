// Leetcode 257. Binary Tree Paths


#include <bits/stdc++.h>
using namespace std;

// 🔹 Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> ans;

    // 🔹 DFS function to generate all root-to-leaf paths
    void solve(TreeNode* root, string path) {
        if (!root) return;

        // ✅ Add current node value to path
        if (path.size() == 0) 
            path = to_string(root->val);
        else 
            path += "->" + to_string(root->val);

        // ✅ If it's a leaf node, store the path
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // 🔹 Traverse left and right subtree
        solve(root->left, path);
        solve(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};


// 🔹 Build tree using level-order input
TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.size() == 0 || nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


// 🔹 Main function
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter nodes in level order (use 'null' for empty):\n";
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution obj;
    vector<string> result = obj.binaryTreePaths(root);

    cout << "All root-to-leaf paths:\n";
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}