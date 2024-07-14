#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mmp;
        for (int i = 0; i < nums.size(); i++) {
            mmp[nums[i]] += 1;
        }
        ListNode n_head = ListNode();
        n_head.next = head;
        ListNode* now = head;
        ListNode* last = &n_head;
        while (now != nullptr) {
            if (mmp[now->val]) {
                last->next = now->next;
            }
            else {
                last = last->next;
            }
            now = now->next;
        }
        return n_head.next;
    }
};