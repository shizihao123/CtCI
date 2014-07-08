#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

bool DeleteNode(Node *p) {
    if (p == NULL || p->next == NULL) {
        return false;
    }
    p->value = p->next->value;
    Node *q = p->next;
    p->next = q->next;
    delete q;
    return true;
}

void OutputList(Node* head) {
    Node *p;
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void DeleteList(Node *head) {
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}

int main() {
    Node *head = new Node;
    Node *p = head, *p3, *p7, *p9;
    for (int i = 1; i <= 9; ++i) {
        p->next = new Node(i);
        p = p->next;
        switch(i) {
            case 3: p3 = p; break;
            case 7: p7 = p; break;
            case 9: p9 = p; break;
        }
    }
    OutputList(head);
    DeleteNode(p3);
    OutputList(head);
    DeleteNode(p7);
    OutputList(head);
    DeleteNode(p9);
    OutputList(head);
    DeleteList(head);
    return 0;
}