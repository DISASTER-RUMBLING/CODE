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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        ListNode* now = head->next;
        ListNode* mid = head;
        int times = 2;
        int mid_times = 1;
        while (now) {
            if ((times / 2) != mid_times) {
                mid = mid->next;
                mid_times++;
            }
            now = now->next;
            times++;
        }
        return mid->next;
    }
};