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

// To print the tree
void levelOrderTree(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
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

// Build tree without recursion
void buildTreeFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data" << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Entre left node for : " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Entre right node for : " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {
    node* root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // root = buildTree(root);

    buildTreeFromLevelOrder(root);
    levelOrderTree(root);
}