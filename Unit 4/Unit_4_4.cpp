/* Write a program to illustrate operations on a BST holding numeric keys. 
The menu must include: • Insert • Delete • Find • Show */

#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

// Insert in BST
Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);

    return root;
}

// Find a key
bool findNode(Node* root, int key) {
    if (root == nullptr)
        return false;

    if (root->key == key)
        return true;
    else if (key < root->key)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
}

// Find minimum node (used in delete)
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Delete a key from BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right);
        root->key = temp->key; // copy successor value
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Show BST (Inorder Traversal)
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\n--- BST OPERATIONS MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            root = insertNode(root, key);
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            break;

        case 3:
            cout << "Enter key to find: ";
            cin >> key;
            if (findNode(root, key))
                cout << "Key FOUND\n";
            else
                cout << "Key NOT FOUND\n";
            break;

        case 4:
            cout << "BST (Inorder): ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
