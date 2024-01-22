#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
    int val;
    struct ListNode* next;
    
};

 //给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 //如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 //为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 //如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 //例如：传入链表[3，0，2，4]的首地址，最后一个节点的next指向第二个节点(数字为0的节点)
 //要求传出0节点的地址


 //思路：采用双指针法，假设head距离循环链表第一个节点a个节点，循环链表中有x个节点
 //当slow指针恰好走到循环链表的第一个节点时，slow走了a个节点，fast走了2a个节点
 //然后在走x-a次，slow指针和fast指针第一次相遇
 //此时俩指针都距离循环链表第一个节点a个节点
 //让其中一节点返回头节点，然后同时向后走一个节点
 //当俩指针再次相遇时，即为循环链表的第一个节点

struct ListNode* detectCycle(struct ListNode* head) {
    //定义俩指针指向首节点
    struct ListNode* fast = head, * slow = head;
    //让俩指针同时移动，fast一次移动俩个节点，slow一次移动一个节点
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        //当俩节点第一次相遇时，跳出该循环
        if (slow == fast) {
            break;
        }
    }
    //让slow指针重新指向head（即链表首地址
    slow = head;
    //判断fast是否为空指针或者是下一个节点为空
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    //让fast和slow同时向后走一个节点
    while (slow != fast) {
        fast = fast->next, slow = slow->next;
    }
    //返回循环链表的首地址
    return slow;
}