// 700. Search in a Binary Search Tree


/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // Approach 1: Recursive
        // // Base Case
        // if(!root) return false;
        
        // if(root -> data == key) return true;
        
        // if(key > root -> data) return search(root -> right, key);
        // else return search(root -> left, key);
        
        


        // Approach 2: Iterative
        Node* temp = root;
        while(temp) {
            if(temp -> data == key) return true;
            
            if(key > temp -> data) temp = temp -> right;
            else temp = temp -> left;
        }
        
        return false;
    }
};