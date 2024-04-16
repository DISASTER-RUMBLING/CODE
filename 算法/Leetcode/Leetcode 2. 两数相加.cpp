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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* now = head;
        int flag = 0, sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* p = new ListNode(sum % 10);
            now->next = p;
            now = now->next;
            sum /= 10;
        }
        if (sum > 0) {
            ListNode* p = new ListNode(sum);
            now->next = p;
            now = now->next;
        }

        return head->next;
    }
};