/*Write a Program to create a Binary Tree and perform the following Recursive 
operations on it. a. Inorder Traversal b. Preorder Traversal c. Display Number of 
Leaf Nodes d. Mirror Image*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create binary tree
Node* createTree() {
    int x;
    cout << "Enter data (-1 for no node): ";
    cin >> x;

    if (x == -1) 
        return nullptr;

    Node* newNode = new Node(x);

    cout << "Enter left child of " << x << ":\n";
    newNode->left = createTree();

    cout << "Enter right child of " << x << ":\n";
    newNode->right = createTree();

    return newNode;
}

// Inorder Traversal (LNR)
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (NLR)
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Count Leaf Nodes
int countLeaf(Node* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// Mirror Image
Node* mirror(Node* root) {
    if (root == nullptr) 
        return nullptr;

    // swap the left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // recursively mirror the subtrees
    mirror(root->left);
    mirror(root->right);

    return root;
}


int main() {
    Node* root = nullptr;

    cout << "Create Binary Tree:\n";
    root = createTree();

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nNumber of Leaf Nodes: " << countLeaf(root);

    cout << "\n\nCreating Mirror Image...\n";
    mirror(root);

    cout << "Inorder Traversal of Mirror Tree: ";
    inorder(root);

    return 0;
}
