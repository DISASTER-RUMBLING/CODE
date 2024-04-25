#define _CRT_SECURE_NO_WARNINGS
#include<stack>

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
    bool isPalindrome(ListNode* head) {
        stack<int> sta;
        ListNode* now = head;
        while (now) {
            sta.push(now->val);
            now = now->next;
        }
        now = head;
        while (now) {
            if (now->val == sta.top()) {
                sta.pop();
                now = now->next;
            }
            else {
                return false;
            }
        }
        return sta.empty();
    }
};