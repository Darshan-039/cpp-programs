#include <iostream>
#include <queue>
using namespace std;

class node {
public: 
    int data;
    node* left;
    node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }

};


node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    
    root = new node(data);

    if(data == -1) return NULL;

    cout << "Enter the data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}


void levelOrderTree(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        

        if(temp == NULL) {
            // current level has traversed full
            cout << endl;
            // queue still has some nodes
            if(!q.empty()) q.push(NULL);
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}


void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    
    // LNR
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(node* root) {
    if(root == NULL) {
        return;
    }
    
    // NLR
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root) {
    if(root == NULL) {
        return;
    }
    
    // LRN
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main() {
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    levelOrderTree(root);
    cout << endl << "Inorder is : " << endl;
    inorder(root);
    
    cout << endl << "preorder is : " << endl;
    preorder(root);

    cout << endl << "postorder is : " << endl;
    postorder(root);
}