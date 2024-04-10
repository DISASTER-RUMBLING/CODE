#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>
using namespace std;


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, int> PII;
        set<PII> s;
        for (int i = 0, n = lists.size(); i < n; i++) {
            if (lists[i] == nullptr) {
                continue;
            }
            s.insert(PII(lists[i]->val, i));
        }
        ListNode new_head, * p = &new_head, * q;
        while (s.size()) {
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];
            lists[a.second] = lists[a.second]->next;
            p->next = q;
            q->next = nullptr;
            p = q;
            if (lists[a.second]) {
                s.insert(PII(lists[a.second]->val, a.second));
            }
        }
        return new_head.next;
    }
};