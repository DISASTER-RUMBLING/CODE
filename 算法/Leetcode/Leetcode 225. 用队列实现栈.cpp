#define _CRT_SECURE_NO_WARNINGS
#include<deque>

using namespace std;

class MyStack {
public:

    deque<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push_back(x);
    }

    int pop() {
        int i = que.back();
        que.pop_back();
        return i;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};