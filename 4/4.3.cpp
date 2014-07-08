#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int value): value(value), left(NULL), right(NULL){}
};

TreeNode* CreateTree(int a[], int n) {
    if (n <= 0) return NULL;
    if (n == 1) return new TreeNode(a[0]);
    TreeNode *root = new TreeNode(a[n / 2]);
    root->left = CreateTree(a, n / 2);
    root->right = CreateTree(a + n / 2 + 1, n - n / 2 - 1);
    return root;
}