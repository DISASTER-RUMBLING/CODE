#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//题目:给你一个链表的头节点 ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 指针再次到达，则链表中存在环。
struct ListNode {
    int val;
    struct ListNode* next;
    
};

bool hasCycle(struct ListNode* head) {
    //判断传入的指针及其指向是否为空
    if (head == NULL || head->next == NULL) {
        return false;
    }
    //使用双指针，一个快，一个慢
    struct ListNode* slow = head, * fast = head;
    //判断俩指针指向的地址是否会相等或者是一方遇到NULL
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        //若俩指针指向的地址相等，则说明是循环链表
        if (slow == fast) {
            return true;
        }
    }
    //若俩指针不会相遇，则说明不是循环链表
    return false;
}