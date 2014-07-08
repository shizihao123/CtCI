#include <iostream>
#include <cmath>

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

bool isBalance(TreeNode *root, int &depth) {
    if (root == NULL) {
        depth = 0;
        return true;
    }
    int left_depth, right_depth;
    if (isBalance(root->left, left_depth)
            && isBalance(root->right, right_depth)) {
        depth = max(left_depth, right_depth) + 1;
        return std::abs(left_depth - right_depth) <= 1;
    }
    return false;
}
