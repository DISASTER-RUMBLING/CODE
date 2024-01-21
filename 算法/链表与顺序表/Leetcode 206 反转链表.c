#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//题目:给你单链表的头节点 head ，请你反转链表，并返回反转后的链表头部

struct ListNode {
    int val;
    struct ListNode* next;    
};

struct ListNode* reverseList(struct ListNode* head) {
    //判断是否传入空指针或者是只有一个节点的链表
    if (head == NULL || head->next == NULL) {
        return head;
    }
    //因为下一个节点为反转后的最后的一个节点，所以定义一个结构体指针指向当前节点的下一个节点
    struct ListNode* tail = head->next;
    //定义一个结构体指针用于接收反转后的链表的头地址
    struct ListNode* new_head = reverseList(head->next);
    //将当前的头节点所指向的下一个节点改为NULL
    //因为原来的下一个节点是反转后的最后一个节点，其指针会指向NULL
    head->next = tail->next;
    //将反转后的最后一个节点的指向改为指向该头节点，让该头节点作为反转后的最后的一个节点，并且指向NULL
    tail->next = head;
    return new_head;
}