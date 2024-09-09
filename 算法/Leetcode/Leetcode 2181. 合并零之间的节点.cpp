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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* now = head->next->next;
        ListNode* sum = head->next;
        ListNode* new_head = head->next;
        head->next = nullptr;
        while (now) {
            if (now->val) {
                sum->val += now->val;
            }
            else {
                sum->next = now->next;
                sum = sum->next;
                if (now->next) {
                    now = now->next;
                }
            }
            now = now->next;
        }
        return new_head;
    }
};