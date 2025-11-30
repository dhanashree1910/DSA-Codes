/*Write a Program to create a Binary Tree Search and Find Minimum/Maximum in 
BST*/

#include<iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int v) {
        value = v;
        left = right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);

    if (val < root->value)
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);

    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root;
}

TreeNode* findMax(TreeNode* root) {
    while (root->right)
        root = root->right;
    return root;
}

int main() {
    TreeNode* root = nullptr;

    int values[] = {10, 9, 8, 7, 16, 15, 4, 11};
    for (int v : values)
        root = insert(root, v);

    cout << "Maximum: " << findMax(root)->value << endl;
    cout << "Minimum: " << findMin(root)->value << endl;

    return 0;
}
