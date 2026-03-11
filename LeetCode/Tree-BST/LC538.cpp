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
class Solution {    
public: 
    int sum = 0;

    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;

        convertBST(root -> right);

        sum += root -> val;
        root -> val = sum;

        convertBST(root -> left);

        return root;
    }
};