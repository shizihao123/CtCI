#include <iostream>
#include <stack>

using namespace std;

template <class T>
void SortStack(stack<T> &stack1) {
    int n = stack1.size();
    if (n <= 1) return ;
    stack<T> stack2;
    while (stack2.size() < n) {
        int min_value = stack1.top();
        int sorted = stack2.size();
        while (!stack1.empty()) {
            min_value = min(stack1.top(), min_value);
            stack2.push(stack1.top());
            stack1.pop();
        }
        int cnt = 0;
        while (stack2.size() > sorted) {
            if (stack2.top() == min_value) {
                ++ cnt;
            } else {
                stack1.push(stack2.top());
            }
            stack2.pop();
        }

        for (int i = 0; i < cnt; ++i) {
            stack2.push(min_value);
        }
    }
    while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
}

int main() {
    stack<int> stk;
    for (int i = 0; i < 10; ++i) {
        stk.push(rand() % 10);
    }
    SortStack(stk);
    for (int i = 0; i < 10; ++i) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
    return 0;
}