#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <class T>
struct Node {
    Node<T> *left, *right;
    int size;
    T key;
    Node(T key): key(key), left(NULL), right(NULL), size(1) {}
};

template <class T>
class BST {
    public:

        BST(): root(NULL){}

        virtual ~BST() { Clear(root); }

        Node<T>* Insert(T key) {
            Node<T> *node = new Node<T>(key);
            Insert(root, node);
            return node;
        }

        int Rank(T key) {
            Node<T> *prt = root;
            int rank = 0;
            while (prt) {
                if (prt->key <= key) {
                    if (prt->left) {
                        rank += prt->left->size;
                    }
                    ++ rank;
                    prt = prt->right;
                } else {
                    prt = prt->left;
                }
            }
            return rank - 1;
        }

    private:

        void Clear(Node<T> *root) {
            if (root == NULL) return;
            Clear(root->left);
            Clear(root->right);
            delete root;
        }

        void Insert(Node<T> *&root, Node<T> *node) {
            if (root == NULL) {
                root = node;
                return ;
            }
            ++ root->size;
            if (node->key <= root->key) {
                Insert(root->left, node);
            } else {
                Insert(root->right, node);
            }
        }
        Node<T> *root;
};

class Solution {
    public:
        void Track(int x) {
            tree.Insert(x);
        }

        int GetRankOfNumber(int x) {
            return tree.Rank(x);
        }
    private:
        BST<int> tree;
};


int main() {
    Solution solution;
    vector<int> stream = {5, 1, 4, 4, 5, 9, 7, 13, 3};
    for (int i = 0; i < stream.size(); ++i) {
        solution.Track(stream[i]);
    }
    cout << solution.GetRankOfNumber(1) << endl;
    cout << solution.GetRankOfNumber(3) << endl;
    cout << solution.GetRankOfNumber(4) << endl;
    return 0;
}

