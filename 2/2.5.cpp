#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

void DeleteList(Node *head) {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}

void OutputList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

Node* GenNumber(int n) {
    Node *head = new Node(rand() % 10);
    Node *p = head;
    for (int i = 2; i < n; ++i) {
        p->next = new Node(rand() % 10);
        p = p->next;
    }
    if (n >= 2) p->next = new Node(rand() % 9 + 1); // first digit can't be 0
    return head;
}

void ReverseList(Node *head) {
    if (head == NULL || head->next == NULL) return ;
    Node *new_head, *p;
    for (Node *h = head, *p = head; p; p = h) {
        h = h->next;
        p->next = new_head;
        new_head = p;
    }
    for (p = new_head; p->next != head; p = p->next);
    head->next = new_head->next;
    p->next = new_head;
    new_head->next = NULL;

    int temp = head->value;
    head->value = new_head->value;
    new_head->value = temp;
}

Node* AddList1(Node *a, Node *b) {
    int remind = 0;
    Node *ans = NULL, *ans_tail = NULL;
    while (a || b) {
        if (a) {
            remind += a->value;
            a = a->next;
        }
        if (b) {
            remind += b->value;
            b = b->next;
        }
        Node *new_node = new Node(remind % 10);
        remind /= 10;
        if (ans_tail) ans_tail->next = new_node, ans_tail = new_node;
        else ans = ans_tail = new_node;
    }
    return ans;
}

Node* AddList2(Node *a, Node *b) {
    ReverseList(a);
    ReverseList(b);
    Node *c = AddList1(a, b);
    ReverseList(c);
    return c;
}

int main() {
    Node* a = GenNumber(3);
    OutputList(a);
    Node* b = GenNumber(5);
    OutputList(b);

    Node* c = AddList1(a, b);
    OutputList(c);
    DeleteList(c);

    ReverseList(a);
    OutputList(a);
    ReverseList(b);
    OutputList(b);

    c = AddList2(a, b);
    OutputList(c);
    DeleteList(c);

    DeleteList(a);
    DeleteList(b);
    return 0;
}