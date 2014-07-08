#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int value = 0): value(value), next(NULL){}
};

Node* GetLoopHead1(Node *head) {
    unordered_set<Node*> ptr_set;
    while (ptr_set.find(head) == ptr_set.end()) {
        ptr_set.insert(head);
        head = head->next;
    }
    return head;
}

Node* GetLoopHead2(Node *head) {
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (fast == NULL || fast->next == NULL) return NULL;
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

int main() {
    Node *head = new Node;
    Node *p = head;
    for (int i = 1; i <= 9; ++i) {
        p->next = new Node(i);
        p = p->next;
    }
    p->next = head->next->next->next;
    cout << GetLoopHead1(head)->value << " " << GetLoopHead2(head)->value << endl;
    return 0;
}