#define _CRT_SECURE_NO_WARNINGS
#include<deque>

using namespace std;

class MyCircularQueue {
public:

    struct node {
        deque<int> que;
        int x;
    };

    node p;

    MyCircularQueue(int k) {
        p.x = k;
    }

    bool enQueue(int value) {
        if (p.que.size() == p.x) {
            return false;
        }
        else {
            p.que.push_back(value);
        }
        return true;
    }

    bool deQueue() {
        if (p.que.size() > 0) {
            p.que.pop_front();
            return true;
        }
        return false;
    }

    int Front() {
        if (p.que.size() == 0) {
            return -1;
        }
        return p.que.front();
    }

    int Rear() {
        if (p.que.size() == 0) {
            return -1;
        }
        return p.que.back();
    }

    bool isEmpty() {
        return p.que.empty();
    }

    bool isFull() {
        return p.que.size() == p.x;
    }
};