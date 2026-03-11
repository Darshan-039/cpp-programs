// Leetcode 99. Recover Binary Search Tree







// Approach -/ Inorder Traversal of BST is in sorted order. So we will do inorder traversal and find the two nodes which are not in order and swap their values.


// class Solution {
// public:
//     TreeNode* prev = NULL;
//     TreeNode* first = NULL;
//     TreeNode* sec = NULL;

//     void inorder(TreeNode* root) {
//         if(!root) return;

//         inorder(root -> left);

//         if(prev && prev -> val > root -> val) {
//             if(!first) first = prev;
//             sec = root;
//         }

//         prev = root;

//         inorder(root -> right);
//     }


//     void recoverTree(TreeNode* root) {
//         inorder(root);

//         int temp = first -> val;
//         first -> val = sec -> val;
//         sec -> val = temp;
//     }
// };

















// Approach - 2/ We can also do Morris Traversal to achieve O(1) space complexity. In this approach we will find the two nodes which are not in order and swap their values.

class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void recoverTree(TreeNode* root) {
        while(root) {
            if(!root -> left) {
                if(prev && prev -> val > root -> val) {
                    if(!first) first = prev;
                    sec = root;
                }
                prev = root;
                root = root -> right;
            }
            else {
                TreeNode* IP = root -> left;
                while(IP -> right && IP -> right != root) IP = IP -> right;

                if(!IP -> right) {
                    IP -> right = root;
                    root = root -> left;
                }
                else {
                    if(prev && prev -> val > root -> val) {
                        if(!first) first = prev;
                        sec = root;
                    }
                    prev = root;
                    IP -> right = NULL;
                    root = root -> right;
                }
            }
        }
        

        if(first && sec) {
            int temp = first -> val;
            first -> val = sec -> val;
            sec -> val = temp;
        }
    }
};