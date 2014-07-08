#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int value): value(value), left(NULL), right(NULL) {}
};

/*
 *           4
 *         /   \
 *        -1    2
 *       /     /
 *      -3    4
 *       \   / \
 *        6 3   2
 */
TreeNode * CreateTree() {
    int id = 0;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(-3);
    root->right->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);
    root->right->left->left = new TreeNode(3);
    root->right->left->right = new TreeNode(2);
    return root;
}

int GetDepth(TreeNode *root) {
    if (root == NULL) return 0;
    return std::max(GetDepth(root->left), GetDepth(root->right));
}

void DFS(TreeNode *root, int path[], int level, int target) {
    if (!root) return ;
    path[level] = root->value;
    int sum = 0;
    for (int i = level; i >= 0; --i) {
        sum += path[i];
        if (sum == target) {
            for (int l = i; l <= level; ++l) {
                std::cout << path[l] << " ";
            }
            std::cout << std::endl;
        }
    }
    DFS(root->left, path, level + 1, target);
    DFS(root->right, path, level + 1, target);
}

void SumPath(TreeNode *root, int target) {
    if (!root) return ;
    int path[GetDepth(root)];
    DFS(root, path, 0, target);
}

int main() {
    TreeNode *root = CreateTree();
    SumPath(root, 6);
    return 0;
}
