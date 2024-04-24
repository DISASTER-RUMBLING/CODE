#define _CRT_SECURE_NO_WARNINGS
#include<stack>

using namespace std;

class MyQueue {
public:

    stack<int>sta1;
    stack<int>sta2;

    MyQueue() {

    }

    void push(int x) {
        sta1.push(x);
    }

    int pop() {
        if (sta2.empty()) {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        int x = sta2.top();
        sta2.pop();
        return x;
    }

    int peek() {
        if (sta2.empty()) {
            while (!sta1.empty()) {
                sta2.push(sta1.top());
                sta1.pop();
            }
        }
        return sta2.top();
    }

    bool empty() {
        return sta1.empty() && sta2.empty();
    }
};