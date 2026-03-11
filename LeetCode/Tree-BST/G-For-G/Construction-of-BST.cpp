#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    // Base Case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root -> data) {
        // Right part me insert kro
        root -> right = insertIntoBST(root -> right, data);
    }
    else {
        // Left part me insert kro
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }

        
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);
    
    cout << "Printing the tree" << endl;
    levelOrderTree(root);
}