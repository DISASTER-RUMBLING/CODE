#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//题目：删除链表中第N个节点

struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //定义并增加一个虚拟头节点
    struct ListNode* new_head = malloc(sizeof(struct ListNode));
    new_head->next = head;
    //创建俩结构体指针
    struct ListNode* last = new_head, * tail = head;
    //使用for循环使tail指针向后移动n-1个
    for (int i = 0; i < n - 1; i++) {
        tail = tail->next;
    }
    //判断tail指针是否指向NULL，是则说明要删除第一个节点
    if (tail->next == NULL) {
        return head->next;
    }
    //双指针使用while向后遍历，直到tail指向NULL
    while (tail->next) {
        tail = tail->next, last = last->next;
    }
    //将tail改为指向要被删除的节点
    tail = last->next;
    //将要被删除的节点所指向的下一个地址赋予该节点的前一个节点的指向
    last->next = tail->next;
    //返回头节点
    return head;
}