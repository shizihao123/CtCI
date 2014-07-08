#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

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

bool IsPalindrome(Node *head) {
    OutputList(head);
    if (!head || !head->next) return true;
    Node *p = head, *q = head;
    while (p && p->next) {
        p = p->next->next;
        q = q->next;
    }
    if (p) q = q->next;
    Node *right_half = q;
    ReverseList(right_half);
    p = head;
    while (q && p->value == q->value) {
        p = p->next;
        q = q->next;
    }
    ReverseList(right_half);
    OutputList(head);
    return q == NULL;
}

int main() {
    Node *head = new Node;
    cout << IsPalindrome(head) << endl;
    Node *p = head;
    for (int i = 1; i <= 9; ++i) {
        p->next = new Node(i);
        p = p->next;
    }
    cout << IsPalindrome(head) << endl;
    for (int i = 9; i >= 0; --i) {
        p->next = new Node(i);
        p = p->next;
    }
    cout << IsPalindrome(head) << endl;
    DeleteList(head);
    return 0;
}