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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* d_head = new ListNode(0);
        d_head->next = head;
        ListNode* now = d_head->next;
        ListNode* tail;
        ListNode* last = d_head;
        while (now != nullptr && now->next != nullptr) {
            if (now->val == now->next->val) {
                tail = now;
                while (tail->next != nullptr && tail->val == tail->next->val) {
                    tail = tail->next;
                }
                last->next = tail->next;
                now = tail->next;
                tail = tail->next;
                continue;
            }
            last = now;
            now = now->next;
        }
        return d_head->next;
    }
};