#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<map>

using namespace std;

class MinStack {
public:
    map<int, int> mmp;
    stack<int> sta;

    MinStack() {

    }

    void push(int val) {
        sta.push(val);
        mmp[val]++;
    }

    void pop() {
        mmp[sta.top()]--;
        if (mmp[sta.top()] == 0) {
            mmp.erase(sta.top());
        }
        sta.pop();
    }

    int top() {
        return sta.top();
    }

    int getMin() {
        return mmp.begin()->first;
    }
};