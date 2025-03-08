#include<iostream>
using namespace std;

class BSTnode {
public:
    int id;
    int quantity;
    BSTnode* left;
    BSTnode* right;

    BSTnode(int ID, int q) {
        id = ID;
        quantity = q;
        left = NULL;
        right = NULL;
    }
};

BSTnode* insert(BSTnode* root, int ID, int q) {
    if (root == NULL) {
        return new BSTnode(ID, q);
    }
    if (ID < root->id) {  // Change here: compare ID instead of quantity
        root->left = insert(root->left, ID, q);
    } else {  // Including IDs that are equal to go to the right
        root->right = insert(root->right, ID, q);
    }
    return root;
}

void inorder(BSTnode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "ID: " << root->id << " Quantity: " << root->quantity << endl;
        inorder(root->right);
    }
}

void search(BSTnode* root, int id) {
    if (root == NULL) {
        cout << "ID: " << id << " not found." << endl;
        return;
    }
    if (root->id == id) {
        cout << "ID: " << root->id << " with Quantity: " << root->quantity << " Found" << endl;
    } else if (id < root->id) {
        search(root->left, id);
    } else {
        search(root->right, id);
    }
}

void update(BSTnode* root, int id, int q) {
    if (root == NULL) {
        cout << "ID: " << id << " not found for update." << endl;
        return;
    }
    if (root->id == id) {
        root->quantity = q;
        cout << "New Quantity " << root->quantity << " for ID: " << root->id << " Updated" << endl;
    } else if (id < root->id) {
        update(root->left, id, q);
    } else {
        update(root->right, id, q);
    }
}

void maximum(BSTnode* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    cout << "ID: " << root->id << " has Maximum Quantity: " << root->quantity << endl;
}

int main() {
    BSTnode* root = NULL;
    root = insert(root, 101, 10);
    root = insert(root, 202, 20);
    root = insert(root, 303, 30);

    cout << "BST of Products before update:" << endl;
    inorder(root);

    update(root, 202, 40);

    cout << "\nBST of Products after Update:" << endl;
    inorder(root);  // Show the updated tree

    // Searching for ID 101
    search(root, 101);

    maximum(root);

    return 0;
}
