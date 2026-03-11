/*
Definition for a Binary Tree Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    // Time Complexity: O(n)
    int countNodes(Node* root) {
        if(!root) return 0;
    
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    
    bool isCBT(Node* root, int index, int cnt) {
        if(!root) return true;
        
        // If the index assigned to a node is greater than total nodes, 
        // there is a "gap" in the tree, meaning it's not a CBT.
        if(index >= cnt) return false;
        
        // Recursively check left and right children with their calculated indices
        bool left = isCBT(root -> left, 2*index + 1, cnt);
        bool right = isCBT(root -> right, 2*index + 2, cnt);
        
        return left && right;
    }
    
    
    bool MaxOrder(Node* root) {
        if (!root) return true;
        
        if (!root->left && !root->right) return true;
        
        if (!root->right) return root->data >= root->left->data;
        else {
            // 1. Recursively check if left and right subtrees are heaps
            // 2. Check if current root is >= both its immediate children
            bool leftSubtreeOk = MaxOrder(root->left);
            bool rightSubtreeOk = MaxOrder(root->right);
            bool currentRootOk = (root->data >= root->left->data && 
                                  root->data >= root->right->data);
            
            return leftSubtreeOk && rightSubtreeOk && currentRootOk;
        }   
    }
    

    bool isHeap(Node* tree) {
        int index = 0;
        int totalCount = countNodes(tree); // Get total node count
        
        // A Binary Tree is a Heap if:
        // 1. It is a Complete Binary Tree (isCBT)
        // 2. It follows the Max-Heap order (MaxOrder)
        return isCBT(tree, index, totalCount) && MaxOrder(tree);
    }
};