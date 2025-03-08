#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Insert nodes into binary tree
Node* insertnode(Node* node, int value) {
    if (!node)
        return new Node(value);

    if (!node->left)
        node->left = insertnode(node->left, value);
    else if (!node->right)
        node->right = insertnode(node->right, value);
    else
        insertnode(node->left, value);

    return node;
}

// Helper to find the rightmost node in a subtree (used for deletion in binary tree)
Node* findRightmost(Node* root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

// Recursive deletion for binary tree (not a BST)
Node* deleteInBinaryTree(Node* root, int key) {
    if (!root) return nullptr;

    if (root->data == key) {
        // If the node has two children, replace it with the rightmost node in its left subtree
        if (root->left && root->right) {
            Node* rightmost = findRightmost(root->left);
            root->data = rightmost->data;
            root->left = deleteInBinaryTree(root->left, rightmost->data);
        }
        // If the node has one child or no children, replace it with that child or nullptr
        else {
            Node* child = root->left ? root->left : root->right;
            delete root;
            return child;
        }
    } else {
        root->left = deleteInBinaryTree(root->left, key);
        root->right = deleteInBinaryTree(root->right, key);
    }
    return root;
}

// Inorder traversal for displaying the tree
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

// Store inorder traversal of binary tree in array
void storeinorder(Node* root, int arr[], int& i) {
    if (!root) return;
    storeinorder(root->left, arr, i);
    arr[i++] = root->data;
    storeinorder(root->right, arr, i);
}

// Sort the array
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Convert sorted array to BST
void arraytobst(Node* root, int arr[], int& i) {
    if (!root) return;
    arraytobst(root->left, arr, i);
    root->data = arr[i++];
    arraytobst(root->right, arr, i);
}

// BST deletion
Node* deleteInBST(Node* root, int key) {
    if (!root) return root;

    // Traverse to the node to be deleted
    if (key < root->data)
        root->left = deleteInBST(root->left, key);
    else if (key > root->data)
        root->right = deleteInBST(root->right, key);
    else {
        // Node found, delete it
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Find the inorder successor
        Node* successor = root->right;
        while (successor->left)
            successor = successor->left;

        root->data = successor->data;
        root->right = deleteInBST(root->right, successor->data);
    }
    return root;
}

int main() {
    // Construct binary tree
    Node* root = nullptr;
    root = insertnode(root, 9);
    root = insertnode(root, 1);
    root = insertnode(root, 3);
    root = insertnode(root, 2);
    root = insertnode(root, 7);
    root = insertnode(root, 4);
    root = insertnode(root, 5);

    // Display inorder traversal of the binary tree
    cout << "Inorder traversal of the binary tree: ";
    inorder(root);
    cout << endl;

    // Delete a node in the binary tree
    root = deleteInBinaryTree(root, 3);
    cout << "Binary tree after deleting node 3: ";
    inorder(root);
    cout << endl;

    // Convert binary tree to BST
    int arr[7];
    int i = 0;
    storeinorder(root, arr, i);
    sort(arr, i);
    i = 0;
    arraytobst(root, arr, i);

    // Display inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    // Delete a node in the BST
    root = deleteInBST(root, 7);
    cout << "BST after deleting node 7: ";
    inorder(root);
    cout << endl;

    return 0;
}
