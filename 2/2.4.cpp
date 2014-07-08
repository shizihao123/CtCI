#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

void Partition(Node *head, int x) {
    Node *less_tail = NULL, *noless_head = NULL, *noless_tail = NULL, *first_less = head;
    while (first_less && first_less->value >= x) first_less = first_less->next;
    if (!first_less) return;
    // keep head is always head
    int temp = head->value;
    head->value = first_less->value;
    first_less->value = temp;

    for (Node *p = head; p; p = head) {
        head = head->next;
        if (p->value < x) {
            if (less_tail) less_tail->next = p;
            less_tail = p;
        } else {
            if (noless_tail) noless_tail->next = p;
            else noless_head = p;
            noless_tail = p;
        }
    }
    less_tail->next = noless_head;
    if (noless_tail) noless_tail->next = NULL;
}

void OutputList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
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
    Node *p = head, *p3, *p7, *p9;
    for (int i = 1; i <= 9; ++i) {
        p->next = new Node(rand() % 10);
        p = p->next;
    }
    OutputList(head);
    Partition(head, -1);
    OutputList(head);
    Partition(head, 4);
    OutputList(head);
    Partition(head, 10);
    OutputList(head);
    DeleteList(head);
    return 0;
}