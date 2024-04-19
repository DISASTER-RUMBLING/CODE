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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* n_head = new ListNode(0);
        n_head->next = head;
        ListNode* last = n_head;
        ListNode* now = head;
        while (now != nullptr) {
            if (now->val == val) {
                last->next = now->next;
                now = now->next;
                continue;
            }
            last = now;
            now = now->next;
        }
        return n_head->next;
    }
};