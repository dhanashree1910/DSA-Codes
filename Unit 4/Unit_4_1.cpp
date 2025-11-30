/*Write a program to perform Binary Search Tree (BST) operations (Create, Insert, 
Delete, Levelwise  display ) */

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = nullptr;
    }
};

// INSERT NODE IN BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// FIND MINIMUM NODE (used for delete)
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// DELETE NODE IN BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
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
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;  // copy inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// LEVEL-WISE DISPLAY (BFS)
void levelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "\nLevel-wise Display:\n";
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Level-wise Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            root = insertNode(root, val);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;

        case 3:
            levelOrder(root);
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
