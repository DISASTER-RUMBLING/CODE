#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ret;
        ListNode* p = &ret;
        p->next = NULL;
        while (list1 || list2) {
            if (list2 == NULL || (list1 && list1->val <= list2->val)) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        return ret.next;
    }
};