#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
    
};

//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//例如输入：有链表[1，2，3，4，5]，输入head，2，4
//要求返回的链表为[1，4，3，2，5]

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    //判断是否为需要反转的最后一个链表，若是则返回该节点的地址
    if (left == right || !head || !head->next) {
        return head;
    }
    //判断是否进入需要反转的节点群
    if (left != 1) {
        //此时未进入
        //让head直接指向反转后的首节点地址
        head->next = reverseBetween(head->next, left - 1, right - 1);
    }
    //此时已进入
    else {
        //定义俩结构体指针，用于接收反转后的首地址和即将插入反转后的最后一个节点
        struct ListNode* new_head = reverseBetween(head->next, left, right - 1), * tail = head->next;
        ///tail的下一个指向为反转后的首节点地址，让head指向其
        head->next = tail->next;
        tail->next = head;
        head = new_head;
    }
    return head;
}
