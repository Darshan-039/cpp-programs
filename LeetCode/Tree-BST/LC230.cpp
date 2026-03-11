// Leetcode 230. Kth Smallest Element in a BST




class Solution {
public:
//  Approach -1 : Using Inorder Traversal (Recursive)


    // int solve(Node* root, int &i, int k) {
    //     if(!root) return -1;
        
    //     int left = solve(root -> left,i,k);
        
    //     if(left != -1) return left;
        
    //     i++;
    //     if(i == k) return root -> data;
        
    //     return solve(root -> right, i, k);
    // }
    




// Approach - 2 : Using Morris Inorder Traversal (Iterative)
    int kthSmallest(Node *root, int k) {
        int i = 0;
        
        while(root) {
            if(!root -> left) {
                i++;
                if(i == k) return root -> data;
                root = root -> right;
            }
            else {
                // Find Predecessor
                Node* temp = root -> left;
                while(temp -> right && temp -> right != root) temp = temp -> right;
                
                // Make a temporary Link
                if(!temp -> right) {
                    temp -> right = root;
                    root = root -> left;
                }
                else {
                    temp -> right = NULL;
                    i++;
                    if(i == k) return root -> data;
                    root = root -> right;
                }
            }
        }
        
        return -1;
    }
};










