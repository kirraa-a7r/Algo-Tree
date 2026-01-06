#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void InOrder(TreeNode* root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right); 
}

int main() {
    TreeNode* root = nullptr;

    int data[] = {
        2, 4, 6, 8,
        5, 10, 15,
        20, 30, 40, 50,
        31, 35, 41, 47
    };

    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, data[i]);
    }

    cout << "InOrder Traversal: ";
    InOrder(root);
    cout << endl;

    return 0;
}
