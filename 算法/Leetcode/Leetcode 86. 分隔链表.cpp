#define _CRT_SECURE_NO_WARNINGS

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* big_head = new ListNode(0);
        ListNode* small_head = new ListNode(0);
        ListNode* big = big_head;
        ListNode* small = small_head;
        ListNode* now = head;
        while (now != nullptr) {
            if (now->val < x) {
                small->next = now;
                small = small->next;
            }
            else {
                big->next = now;
                big = big->next;
            }
            now = now->next;
        }
        small->next = big_head->next;
        big->next = nullptr;
        return small_head->next;
    }
};