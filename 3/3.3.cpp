#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class SetOfStacks {
public:
    static const int pop_fail = -1;

    SetOfStacks(int n): capacity_(n), last_size(n) { assert(n > 0); }
    
    void push(int value) {
        if (last_size == capacity_) {
            stacks_.push_back(vector<int>(capacity_));
            last_size = 0;
        }
        stacks_[stacks_.size() - 1][last_size++] = value; 
    }
    
    int pop() {
        if (stacks_.size() == 0) return pop_fail;
        int value = stacks_[stacks_.size() - 1][--last_size];
        CheckLast();
        return value;
    }

    int popAt(int index) {
        if (index >= stacks_.size()) return pop_fail;
        if (index == stacks_.size() - 1) return pop();
        int value = stacks_[index][capacity_ - 1];
        for (int i = index + 1; i < stacks_.size(); ++i) {
            stacks_[i - 1][capacity_ - 1] = stacks_[i][0];
            for (int j = 1; j < capacity_; ++j) {
                stacks_[i][j - 1] = stacks_[i][j];
            }
        }
        -- last_size;
        CheckLast();
        return value;
    }

    friend ostream& operator<<(ostream& os, const SetOfStacks& stk);
private:
    void CheckLast() {
        if (last_size == 0 && stacks_.size()) {
            stacks_.pop_back();
            last_size = capacity_;
        }
    }

private:
    int capacity_;
    int last_size;
    vector<vector<int> > stacks_;
};

ostream& operator<<(ostream& os, const SetOfStacks& stk) {
    for (int i = 0; i < stk.stacks_.size() - 1; ++i) {
        for (int j = 0; j < stk.capacity_; ++j) {
            os << stk.stacks_[i][j] << " ";
        }
        os << "| ";
    }
    for (int j = 0; j < stk.last_size; ++j) {
        os << stk.stacks_[stk.stacks_.size() - 1][j] << " ";
    }
    return os;
}

int main() {
    SetOfStacks sstack(4);
    for (int i = 0; i < 10; ++i) {
        sstack.push(i);
    }
    cout << sstack << endl;
    cout << sstack.pop() << endl;
    cout << sstack << endl;
    cout << sstack.popAt(0) << endl;
    cout << sstack << endl;
    return 0;
}