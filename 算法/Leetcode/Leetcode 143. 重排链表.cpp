#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        vector<ListNode*> arr;
        ListNode* now = head;
        while (now) {
            arr.push_back(now);
            now = now->next;
        }
        int tail = arr.size() - 1;
        int nw = 0;
        int times = (arr.size() / 2);
        if (arr.size() % 2 == 0) {
            times--;
        }
        while (times--) {
            arr[tail]->next = arr[nw]->next;
            arr[nw]->next = arr[tail];
            tail--, nw++;
        }
        if (arr.size() % 2 == 0) {
            nw++;
        }
        arr[nw]->next = nullptr;
        return;
    }
};