#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>

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
    unordered_map<ListNode*, bool> mmp;
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while (headA) {
            mmp[headA] = true;
            headA = headA->next;
        }
        while (headB) {
            if (mmp[headB]) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};