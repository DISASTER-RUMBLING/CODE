#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        head->next->next = swapPairs(head->next->next);
        ListNode* new_head = head->next;
        ListNode* next = head->next;
        ListNode* now = head;
        now->next = next->next;
        next->next = now;
        return new_head;
    }
};