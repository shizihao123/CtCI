#include <iostream>
#include <cassert>

using namespace std;

class ThreeStack {
public:
    ThreeStack(int n) {
        capacity_ = n;
        top1_ = 0;
        top2_ = n - 1;
        top3_ = base3_ = n / 2;
        data_ = new int[capacity_];
        last_shift = 0;
    }

    int size() {
        return top1_ + (capacity_ - 1 - top2_) + (top3_ - base3_);
    }

    virtual ~ThreeStack() {
        delete [] data_;
    }

    bool push(int tag, int value) {
        assert(1<= tag && tag <= 3);
        switch(tag) {
            case 1:
                if (top1_ == base3_ && move(RIGHT) == false) {
                    return false;
                }
                data_[top1_++] = value;
                break;
            case 2:
                if (top3_ > top2_ && move(LEFT) == false) {
                    return false;
                }
                data_[top2_--] = value;
                break;
            case 3:
                if (top3_ > top2_ && move(LEFT) == false) {
                    return false;
                }
                data_[top3_++] = value;
                break;
        }
        return true;
    }

    int pop(int tag) {
        assert(1 <= tag && tag <= 3);
        int value = -1;
        switch(tag) {
            case 1:
                if (top1_ > 0) value = data_[--top1_];
                break;
            case 2:
                if (top2_ < capacity_ - 1) value = data_[++top2_];
                break;
            case 3:
                if (top3_ > base3_) value = data_[--top3_];
                break;
        }
        return value;
    }
private:
    enum MOVE_DIR { LEFT, RIGHT };
    bool move(MOVE_DIR dir) {
        int shift = 0;
        if (dir == RIGHT && last_shift > 0) {
            shift = min(last_shift * 2, top2_ - top3_ + 1);
        } else if (dir == RIGHT && last_shift <= 0) {
            shift = min(1, top2_ - top3_ + 1);
        } else if (dir == LEFT && last_shift < 0) {
            shift = -min(-last_shift * 2, base3_ - top1_);
        } else if (dir == LEFT && last_shift >= 0) {
            shift = -min(1, base3_ - top1_);
        }
        last_shift = shift;
        if (shift == 0) return false;
        if (shift > 0) {
            for (int i = top3_ - 1; i >= base3_; --i) {
                data_[i + shift] = data_[i];
            }
        } else {
            for (int i = base3_; i < base3_; ++i) {
                data_[i + shift] = data_[i];
            }
        }
        base3_ += shift;
        top3_ += shift;
        cout << "log: stack move " << shift << ", base3=" << base3_ << ", top3=" << top3_  << endl;
        return true;
    }

    int *data_;
    int capacity_;
    int top1_, top2_, top3_, base3_;
    int last_shift;
    
};

int main() {
    ThreeStack stk(10);
    for (int i = 0; i < 15; ++i) {
        cout << "push(1, " << i << "): ";
        if (stk.push(1, i)) cout << "success" << endl;
        else cout << "fail" << endl;
    }
    for (int i = 0; i < 15; ++i) {
        cout << "pop(1): ";
        int value = stk.pop(1);
        if (value == -1) cout << "fail" << endl;
        else cout << value << endl;
    }

    for (int i = 0; i < 15; ++i) {
        cout << "push(3, " << i << "): ";
        if (stk.push(3, i)) cout << "success" << endl;
        else cout << "fail" << endl;
    }
    for (int i = 0; i < 5; ++i) {
        cout << "pop(3): ";
        int value = stk.pop(3);
        if (value == -1) cout << "fail" << endl;
        else cout << value << endl;
    }

    for (int i = 0; i < 15; ++i) {
        cout << "push(2, " << i << "): ";
        if (stk.push(2, i)) cout << "success" << endl;
        else cout << "fail" << endl;
    }
    for (int i = 0; i < 15; ++i) {
        cout << "pop(2): ";
        int value = stk.pop(2);
        if (value == -1) cout << "fail" << endl;
        else cout << value << endl;
    }
    return 0;
}