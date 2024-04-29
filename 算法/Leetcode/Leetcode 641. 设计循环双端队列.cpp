#define _CRT_SECURE_NO_WARNINGS
#include<deque>

using namespace std;

class MyCircularDeque {
public:

    struct node {
        deque<int> que;
        int m_size;
        int now;
    }nd;


    MyCircularDeque(int k) {
        nd.m_size = k;
        nd.now = 0;
    }

    bool insertFront(int value) {
        if (nd.m_size == nd.now) {
            return false;
        }
        nd.que.push_front(value);
        nd.now++;
        return 1;
    }

    bool insertLast(int value) {
        if (nd.m_size == nd.now) {
            return false;
        }
        nd.que.push_back(value);
        nd.now++;
        return 1;
    }

    bool deleteFront() {
        if (nd.que.empty()) {
            return false;
        }
        nd.que.pop_front();
        nd.now--;
        return 1;
    }

    bool deleteLast() {
        if (nd.que.empty()) {
            return false;
        }
        nd.que.pop_back();
        nd.now--;
        return 1;
    }

    int getFront() {
        if (nd.que.empty()) {
            return -1;
        }
        return nd.que.front();
    }

    int getRear() {
        if (nd.que.empty()) {
            return -1;
        }
        return nd.que.back();
    }

    bool isEmpty() {
        return nd.now == 0;
    }

    bool isFull() {
        return nd.m_size == nd.now;
    }
};