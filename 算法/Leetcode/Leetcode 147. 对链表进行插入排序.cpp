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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* n_head = new ListNode(-5001, nullptr);
        ListNode* now = head;
        while (now) {
            ListNode* nex = now->next;
            ListNode* tar = n_head;
            while (tar->next != nullptr && tar->next->val < now->val) {
                tar = tar->next;
            }
            now->next = tar->next;
            tar->next = now;
            now = nex;
        }
        return n_head->next;
    }
};