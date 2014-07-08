#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    int size;
    TreeNode *left, *right;
    TreeNode(int value): value(value), left(NULL), right(NULL), size(0) {}
};

int CalcSize(TreeNode *root) {
    if (root == NULL) return 0;
    root->size = CalcSize(root->left) + CalcSize(root->right) + 1;
    return root->size;
}

bool IsIdentical(TreeNode *tree1, TreeNode *tree2) {
    if (!tree1 || !tree2) {
        return tree1 == tree2;
    }
    if (tree1->value != tree2->value) {
        return false;
    }
    if (!IsIdentical(tree1->left, tree2->right)) {
        return false;
    }
    if (!IsIdentical(tree1->right, tree2->right)) {
        return false;
    }
    return true;
}

bool IsSubtree(TreeNode *tree1, TreeNode *tree2) {
    if (!tree2) return true;
    if (!tree1 || tree1->size < tree2->size) return false;
    if (tree1 == tree2) return true; // pointer to same memory
    if (tree1->size == tree2->size) {
        return IsIdentical(tree1, tree2);
    }
    return IsSubtree(tree1->left, tree2) || IsSubtree(tree1->right, tree2);
}


void  GenTree(TreeNode *&root, int level, int value) {
    if (level <= 0) { 
        root = NULL;
        return ;
    }
    root = new TreeNode(value);
    GenTree(root->left, level - 1, value);
    GenTree(root->right, level - 1, value);
}

void PrintTree(TreeNode *root) {
    std::vector<TreeNode*> now;
    now.push_back(root);
    while (!now.empty()) {
        std::vector<TreeNode*> next;
        for (int i = 0; i < now.size(); ++i) {
            std::cout << now[i]->value << " ";
            if (now[i]->left) {
                next.push_back(now[i]->left);
            }
            if (now[i]->right) {
                next.push_back(now[i]->right);
            }
        }
        std::cout << std::endl;
        now = next;
    }
}

int main() {
    TreeNode *T1, *T2, *T3, *T4;
    GenTree(T1, 3, 0);
    GenTree(T1->left->right->left, 4, 1);
    GenTree(T1->right->left->right, 4, 2);
    CalcSize(T1);
    GenTree(T2, 3, 1);
    CalcSize(T2);
    GenTree(T3, 4, 2);
    CalcSize(T3);
    GenTree(T4, 3, 3);
    CalcSize(T4);
//    PrintTree(T1);
//    PrintTree(T2);
//    PrintTree(T3);
//    PrintTree(T4);

    std::cout << IsSubtree(T1, T2) << std::endl;
    std::cout << IsSubtree(T1, T3) << std::endl;
    std::cout << IsSubtree(T1, T4) << std::endl;

    return 0;
}
