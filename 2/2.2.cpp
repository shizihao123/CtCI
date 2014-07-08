#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

Node* GetKthToLast(Node *head, int k) {
    assert(k > 0);
    Node *p = head, *q = head;
    for (int i = 0; i < k; ++i) {
        if (p == NULL) return NULL;
        p = p->next;
    }
    while (p) {
        q = q->next;
        p = p->next;
    }
    return q;
}

void DeleteList(Node *head) {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    Node *head = new Node;
    Node *p = head;
    for (int i = 1; i <= 9; ++i) {
        p->next = new Node(i);
        p = p->next;
    }
    cout << GetKthToLast(head, 1)->value << " " 
         << GetKthToLast(head, 5)->value << " "
         << GetKthToLast(head, 10)->value << " " 
         << GetKthToLast(head, 11) << endl;
    DeleteList(head);
    return 0;
}