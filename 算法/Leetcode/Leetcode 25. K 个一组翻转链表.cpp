#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
    ListNode* resereve(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        vector<ListNode*> arr;
        ListNode* tail = head;
        for (int i = 1; i < k; i++) {
            arr.push_back(tail);
            tail = tail->next;
            if (tail == nullptr) {
                return head;
            }
        }
        arr.push_back(tail);
        ListNode* next = tail->next;
        ListNode* last;
        int now = arr.size() - 2;
        while (now >= 0) {
            arr[now]->next = tail->next;
            tail->next = arr[now];
            tail = tail->next;
            now--;
        }
        tail->next = resereve(next, k);
        return arr[k - 1];

    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        return resereve(head, k);

    }
};