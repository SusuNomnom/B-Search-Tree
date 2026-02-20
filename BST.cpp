#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            std::cout << node->key << " ";
            inorder(node->right);
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
    }
    void inorder() {
        inorder(root);
    }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.inorder(); // Output will be: 2 3 4 5 7
    return 0;
}