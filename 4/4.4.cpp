#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode *left, *right, *next;
    TreeNode(int value): value(value), left(NULL), right(NULL), next(NULL){}
};

std::vector<TreeNode*> CreateDepthList(TreeNode *root) {
    std::vector<TreeNode*> result;
    if (root == NULL) return result;
    root->next = NULL;
    result.push_back(root);
    do {
        TreeNode *fhead = result[result.size() - 1];
        TreeNode *chead = NULL, *ctail = NULL;
        while (fhead) {
            if (fhead->left) {
                if (chead == NULL) {
                    chead = ctail = fhead->left;
                } else {
                    ctail->next = fhead->left;
                    ctail = fhead->left;
                }
            }
            if (fhead->right) {
                if (chead == NULL) {
                    chead = ctail = fhead->right;
                } else {
                    ctail->next = fhead->right;
                    ctail = fhead->right;
                }
            }
            fhead = fhead->next;
        }
        if (chead == NULL) break;
        result.push_back(chead);
    } while (true);
    return result;
}

TreeNode * CreateTree() {
    int id = 0;
    TreeNode *root = new TreeNode(id++);
    root->left = new TreeNode(id++);
    root->right = new TreeNode(id++);
    root->left->left = new TreeNode(id++);
    root->right->left = new TreeNode(id++);
    root->left->left->right = new TreeNode(id++);
    root->right->left->left = new TreeNode(id++);
    root->right->left->right = new TreeNode(id++);
    return root;
}

int main() {
    TreeNode *root = CreateTree();
    std::vector<TreeNode*> levellist = CreateDepthList(root);
    for (int i = 0; i < levellist.size(); ++i) {
        for (TreeNode *p = levellist[i]; p; p = p->next) {
            std::cout << p->value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
