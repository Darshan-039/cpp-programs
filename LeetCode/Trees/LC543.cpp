// Title: Diameter of Binary Tree

// Approach - 1



class Solution {
    private:
    int height(Node* root) {
        if(root == NULL) return 0;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
    
    public:
    int diameter(Node* root) {
        if(root == NULL) return 0;
        
        int left = diameter(root -> left);
        int right = diameter(root -> right);
        int combo = height(root -> left) + height(root -> right);
        
        int ans = max(combo, max(left,right));
        return ans;
    }
};




// Approach - 2 (Optimized)

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
    // This helper function returns a pair: {Diameter, Height}
    // Returning both at once prevents multiple redundant visits to the same nodes.
    pair<int,int> diameterFast(Node* root) {
        // Base Case: If the node is NULL, both diameter and height are 0.
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        // Recursive calls to get {Diameter, Height} for both subtrees
        pair<int,int> left = diameterFast(root -> left);
        pair<int,int> right = diameterFast(root -> right);
        
        // Extracting diameter values from the pairs
        int Dleft = left.first;   // Longest path entirely in the left subtree
        int Dright = right.first; // Longest path entirely in the right subtree
        
        // 'combo' represents the longest path passing THROUGH the current root.
        // It is the sum of the heights of the left and right subtrees (Edge count).
        int combo = left.second + right.second;
        
        pair<int,int> ans;
        
        // The diameter at this node is the maximum of:
        // 1. Diameter of the left subtree
        // 2. Diameter of the right subtree
        // 3. The path passing through this root (combo)
        ans.first = max(combo, max(Dleft, Dright));
        
        // Calculate the height for the current node to pass up to the parent.
        // Height = max(left_height, right_height) + 1 node.
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    
    public:
    int diameter(Node* root) {
        // We only care about the first element of the pair (the Diameter)
        return diameterFast(root).first;
    }
};