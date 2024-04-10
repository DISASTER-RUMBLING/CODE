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
 

  //¿ìËÙÅÅÐò
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* p = head, * left = NULL, * right = NULL, * q;
        int mi = p->val, ma = p->val, flag = 0;
        while (p) {
            ma = p->val > ma ? p->val : ma;
            mi = p->val < ma ? p->val : mi;
            p = p->next;
            flag++;
        }
        if (mi == ma) {
            return head;
        }
        p = head;
        int n = (mi + ma) >> 1;
        while (p) {
            q = p->next;
            if (p->val <= n) {
                p->next = left;
                left = p;
            }
            else {
                p->next = right;
                right = p;
            }
            p = q;
        }
        left = sortList(left);
        right = sortList(right);
        p = left;
        while (left->next) {
            left = left->next;
        }
        left->next = right;
        return p;
    }



    //¹é²¢ÅÅÐò

    int Num(ListNode* head) {
        int n = 0;
        while (head) {
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode* Merge_Sort(ListNode* head, int n) {
        if (n <= 1) {
            return head;
        }
        int l = n / 2, r = n - l;
        ListNode* p = head, * p1, ret;
        for (int i = 1; i < l; i++) {
            p = p->next;
        }
        p1 = head;
        ListNode* p2 = p->next;
        p->next = NULL;
        p1 = Merge_Sort(p1, l);
        p2 = Merge_Sort(p2, r);
        p = &ret;
        p->next = NULL;
        while (p1 || p2) {
            if (p2 == NULL || (p1 && p1->val < p2->val)) {
                p->next = p1;
                p = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        return ret.next;
    }

    ListNode* _sortList(ListNode* head) {
        return Merge_Sort(head, Num(head));
    }


};



