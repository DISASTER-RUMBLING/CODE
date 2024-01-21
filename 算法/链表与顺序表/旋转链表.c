#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//例如：输入 head 2
//若链表中为[1 ,2 ,3 ,4 ,5 ]
//则要求旋转后链表序号为 [ 4 ,5 ,1 ,2 ,3 ]


 struct ListNode {
    int val;
    struct ListNode* next;
    
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    //判断是否只有俩个节点
    if (k == 0 || head == NULL || head->next == NULL) {
        return head;
    }
    //定义一个结构体指针指向头部
    struct ListNode* p = head;
    //定义一个整形用于计算有多少个节点
    int time = 1;
    //while循环计算有多少个节点并且让指针p指向最后一个节点
    while (p->next) {
        p = p->next;
        time++;
    }
    //简化k，防止k过大
    if (k % time == 0) {
        return head;
    }
    //让链表变成循环链表
    p->next = head;
    //定义一个结构体指针last
    struct ListNode* last;
    //寻找要被切割的节点的前一个节点，让last指向该节点，让指针p指向旋转后的头地址
    for (int i = 0; i < (1 + time - (k % time)); i++) {
        last = p;
        p = p->next;
    }
    //将该节点的指向切断
    last->next = NULL;
    //返回p指针指向的地址
    return p;
}