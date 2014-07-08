#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right, *parent;
    TreeNode(int value): value(value), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* FindNext(TreeNode *p) {
    if (p->right) {
        p = p->right;
        while (p->left) {
            p = p->left;
        }
    } else {
        while (p->parent && p == p->parent->right) {
            p = p->parent;
        }
        p = p->parent;
    }
    return p;
}

void CreateParent(TreeNode *root, TreeNode* parent = NULL) {
    if (root == NULL) return ;
    root->parent = parent;
    CreateParent(root->left, root);
    CreateParent(root->right, root);
}

/*
 *           5
 *         /   \
 *        3     9
 *       /     /
 *      1     7
 *       \   / \
 *        2 6   8
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

void Print(TreeNode *p) {
    TreeNode *next = FindNext(p);
    if (next) {
        std::cout << p->value << " next is " << next->value << std::endl;
    } else {
        std::cout << p->value << " next is NULL" << std::endl;
    }
    return ;
}

int main() {
    TreeNode *root = CreateTree();
    Print(root);
    Print(root->left);
    Print(root->right);
    Print(root->left->left);
    Print(root->left->left->right);
    Print(root->right->left);
    Print(root->right->left->left);
    Print(root->right->left->right);

    return 0;
}
