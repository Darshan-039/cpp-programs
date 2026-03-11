// Approach - 1: Store the path from root to the target node and then access the k-th ancestor directly.


class Solution {
public:
    int solve(Node* root, int k, int target, vector<int> &path) {
        if (!root) return -1;
        
        // 1. Add current node to the path
        path.push_back(root->data);
        
        // 2. Check if this is the target node
        if (root->data == target) {
            int size = path.size();
            int ancestorIdx = size - k - 1;
            
            // If ancestorIdx is valid, return the ancestor; else return -1
            if (ancestorIdx >= 0) {
                return path[ancestorIdx];
            } else {
                return -1;
            }
        }
        
        // 3. Search in left and right subtrees
        int leftRes = solve(root->left, k, target, path);
        if (leftRes != -1) return leftRes; // Found in left branch, propagate up
        
        int rightRes = solve(root->right, k, target, path);
        if (rightRes != -1) return rightRes; // Found in right branch, propagate up
        
        // 4. Backtrack: remove current node before going back up
        path.pop_back();
        
        return -1;
    }

    int kthAncestor(Node *root, int k, int node) {
        vector<int> path;
        return solve(root, k, node, path);
    }
};






// Approach - 2 : Recursive approach without extra space to store the path.


class Solution {
public:
    Node* solve(Node* root, int &k, int node) {
        if(!root) return NULL;

        if(root -> data == node) {
           return root;
        }

        Node* leftAns = solve(root -> left, k, node);
        Node* rightAns = solve(root -> right, k, node);

        if(!leftAns && rightAns) {
            k--;
            if(k <= 0) {
                // Ans locked
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        
        if(leftAns && !rightAns) {
            k--;
            if(k <= 0) {
                // Ans locked
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }

        return NULL;

    }


    int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node* ans = solve(root, k, node);
        if(!ans || ans -> data == node) return -1;
        else return ans -> data;
    }
};
