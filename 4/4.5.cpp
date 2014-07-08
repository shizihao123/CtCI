#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int value): value(value), left(NULL), right(NULL) {}
};

bool check(TreeNode *root, int &minvalue, int &maxvalue) {
    if (root == NULL) {
        minvalue = INT_MAX;
        maxvalue = INT_MIN;
        return true;
    }
    int lminv, lmaxv, rminv, rmaxv;
    bool result = check(root->left, lminv, lmaxv) && lmaxv <= root->value
        && check(root->right, rminv, rmaxv) && (rminv == INT_MAX || root->value < rminv);
    minvalue = std::min(root->value, lminv);
    maxvalue = std::max(root->value, rmaxv);
    // std::cout << root->value << " " << minvalue << " " << maxvalue << std::endl;
    return result;
}

bool IsBST(TreeNode *root) {
    int minvalue, maxvalue;
    return check(root, minvalue, maxvalue);
}

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
    return root;
}

int main() {
    TreeNode *root = CreateTree();
    std::cout << IsBST(root) << std::endl;
    return 0;
}
