#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *min_ptr;
    Node(int value = 0): value(value), next(NULL), min_ptr(NULL){}
};

class StackWithMin {
public:
    StackWithMin(): head(NULL), min_ptr(NULL){}
    void push(int value) {
        Node *node = new Node(value);
        node->next = head;
        node->min_ptr = min_ptr;
        if (!min_ptr || value < min_ptr->value) {
            min_ptr = node;
        }
        head = node;
    }
    int pop() {
        min_ptr = head->min_ptr;
        int value = head->value;
        Node *p = head;
        head = head->next;
        delete p;
        return value;
    }
    int min() {
        return min_ptr? min_ptr->value: -1;
    }
private:
    Node *head, *min_ptr;
};

int main() {
    StackWithMin mstk;
    for (int i = 0; i < 10; ++i) {
        int value = 20 - i - rand() % 10;
        mstk.push(value);
        cout << "push = " << value << ",  min = " << mstk.min() << endl;
    }
    for (int i = 0; i < 10; ++i) {
        cout << "pop = " << mstk.pop() << ", min = " << mstk.min() << endl;
    }
    
    return 0;
}