#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }
    return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main() {
    // Example usage:
    // Constructing the following binary tree:
    //      1
    //     / \
    //    2   2
    //   / \ / \
    //  3  4 4  3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        cout << "The binary tree is a mirror tree." << endl;
    } else {
        cout << "The binary tree is not a mirror tree." << endl;
    }

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}