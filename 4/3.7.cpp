#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right, *parent;
    TreeNode(int value): value(value), left(NULL), right(NULL), parent(NULL) {}
};

int GetDepth(TreeNode *node) {
    int depth = -1;
    while (node) {
        ++ depth;
        node = node->parent;
    }
    return depth;
}

TreeNode* LCA(TreeNode *node1, TreeNode* node2) {
    int depth1 = GetDepth(node1);
    int depth2 = GetDepth(node2);
    while (node1 != node2) {
        if (depth1 <= depth2) {
            -- depth2;
            node2 = node2->parent;
        } else {
            -- depth1;
            node1 = node1->parent;
        }
    }
    return node1;
}

void CreateParent(TreeNode *root, TreeNode* parent = NULL) {
    if (root == NULL) return ;
    root->parent = parent;
    CreateParent(root->left, root);
    CreateParent(root->right, root);
}

/*
 *          5
 *        /   \
 *       3     9
 *      /     /
 *     1      7
 *      \    /  \
 *       2  6    8
 */

TreeNode * CreateTree() {
    int id = 0;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    CreateParent(root);
    return root;
}

void Print(TreeNode *node1, TreeNode *node2) {
    TreeNode *lac = LCA(node1, node2);
    std::cout << node1->value << " " << node2->value << " " << lac->value << std::endl;
    return ;
}

int main() {
    TreeNode *root = CreateTree();
    Print(root, root->left->left);
    Print(root->left, root->right);
    Print(root->right, root->right->left->left);
    Print(root->left->left, root->left->left->right);
    Print(root->right->left->right, root->left);
    return 0;
}
