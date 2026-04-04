// Leetcode 538. Convert BST to Greater Tree







// Approach - 1:   O(n) time and O(n) space
// class Solution {
// public: 
//     int index = 0;
//     vector<int> ans;

//     void inorder(TreeNode* root) {
//         if(!root) return;

//         inorder(root -> left);
//         ans.push_back(root -> val);
//         inorder(root -> right);
//     }

//     void inorderFill(TreeNode* root, vector<int> &arr) {
//         if(!root) return;

//         inorderFill(root -> left, arr);
//         root -> val = arr[index++];
//         inorderFill(root -> right, arr);
//     }

//     TreeNode* convertBST(TreeNode* root) {
//         if(!root) return root;
//         inorder(root);

//         int n = ans.size();
//         vector<int> suffix(n);
//         suffix[n-1] = ans[n-1];
//         for(int i=n-2; i>=0; i--) suffix[i] = ans[i] + suffix[i+1];

//         inorderFill(root, suffix);

//         return root;
//     }
// };













// Approach - 2:   O(n) time and O(1) space

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {    
public: 
    int sum = 0;  // 🔹 Stores cumulative sum of greater nodes

    // 🔹 Convert BST to Greater Sum Tree
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;

        // 🔸 Step 1: Traverse right subtree (larger values first)
        convertBST(root->right);

        // 🔸 Step 2: Add current node value to sum
        sum += root->val;

        // 🔸 Step 3: Update current node with cumulative sum
        root->val = sum;

        // 🔸 Step 4: Traverse left subtree
        convertBST(root->left);

        return root;
    }
};

// 🔥 Build BST (Level Order Input)
// -1 means NULL
TreeNode* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;

    if (val == -1) return NULL;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->val << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            temp->left = new TreeNode(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->val << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            temp->right = new TreeNode(rightVal);
            q.push(temp->right);
        }
    }

    return root;
}

// 🔥 Inorder Traversal (to print tree)
void inorder(TreeNode* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 🔥 MAIN
int main() {
    Solution sol;

    // Build BST
    TreeNode* root = buildTree();

    cout << "\nInorder before conversion: ";
    inorder(root);

    // Convert BST → Greater Sum Tree
    sol.convertBST(root);

    cout << "\nInorder after conversion: ";
    inorder(root);

    cout << endl;

    return 0;
}