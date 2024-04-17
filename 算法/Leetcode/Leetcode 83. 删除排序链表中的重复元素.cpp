#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* now = head->next;
        ListNode* last = head;
        while (now != nullptr && now->next != nullptr) {
            if (last->val == now->val) {
                last->next = now->next;
                now = now->next;
                continue;
            }
            last = now;
            now = now->next;
        }
        if (now->val == last->val) {
            last->next = now->next;
        }
        return head;
    }
};