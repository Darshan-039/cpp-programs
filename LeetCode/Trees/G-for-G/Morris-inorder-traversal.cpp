int main() {
    vector<int> ans;
    Node* curr = root;

    while(curr) {
        if(!curr -> left) {
            res.push_back(curr -> data);
            curr = curr -> right;
        }
        else {
            // Find the predecessor for inorder traversal
            Node* prev = curr -> left;
            while(prev -> right || prev -> right != curr) {
                prev = prev -> right;
            }

            // Make a temporary link
            if(!prev -> right) {
                prev -> right = curr;
                curr = curr -> left;
            }
            // Revert the link made in
            else {
                prev -> right = NULL;
                res.push_back(curr -> data);
                curr = curr -> right;
            }
        }
    }
}