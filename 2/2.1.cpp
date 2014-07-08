#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

typedef Node* DeleteFunction(Node*);

Node* DeleteDuplicate1(Node* head) {
    unordered_set<int> value_set;
    for (Node *p = head, *q; p; q = p, p = p->next) {
        if (value_set.find(p->value) == value_set.end()) {
            value_set.insert(p->value);
        } else {
            q->next = p->next;
            delete p;
            p = q;
        }
    }
    return head;
}

Node* DeleteDuplicate2(Node* head) {
    for (Node *h = head; h; h = h->next) {
        for (Node *p = h->next, *q = h; p;) {
            if (h->value == p->value) {
                q->next = p->next;
                delete p;
                p = q->next;
            } else {
                q = p;
                p = p->next;
            }
        }
    }
    return head;
}

void OutputList(Node* head) {
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

void check(DeleteFunction *func) {
    Node *head = new Node;
    Node *p = head;
    for (int i = 0; i < 15; ++i) {
        p->next = new Node(rand() % 5);
        p = p->next;
    }
    OutputList(head);
    func(head);
    OutputList(head);
    DeleteList(head);
}

int main() {
    check(DeleteDuplicate1);
    check(DeleteDuplicate2);
    return 0;
}