#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    static const int pop_fail = -1;
    void push(int x) {
        stk_in.push(x);
    }
    int pop() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
        if (stk_out.empty()) return pop_fail;
        int value = stk_out.top();
        stk_out.pop();
        return value;
    }
private:
    stack<int> stk_in, stk_out;
};

int main() {
    MyQueue que;
    for (int i = 0; i < 30; ++i) {
        if (rand() % 3) {
            int value = rand() % 10;
            que.push(value);
            cout << "push: " << value << endl;
        } else {
            cout << "pop: " << que.pop() << endl;
        }
    }
    return 0;
}