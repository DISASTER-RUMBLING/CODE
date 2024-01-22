#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct queue {
	int* data;
	int size, count, head, tail;
}queue;


//初始化队列
queue* Init_Queue(int n) {
	//开辟一个内存大小为结构体queue的空间，并且让p指向该空间的首地址
	queue* p = (queue*)malloc(sizeof(queue));
	//假设存在函数Vector能够开辟n个变量空间，让data指向该空间
	p->data = Vector(n);
	//让count，head，size，tail为0
	p->count = p->head = p->size = p->tail = 0;
	//返回该队列的首地址
	return p;
}

//函数用于判断当前顺序表中是否为空
int Empty(queue* p) {
	return (p->count == 0);
}

//插入一个数据
int Queue_Inerst(queue* p, int val) {
	//判断当前队列是否满了
	if (p->count == p->size) {
		return 0;
	}
	//假设有一个顺序表的函数Insert，需要传入数据的地址，插入的位置，要插入的数字
	//调用该函数
	Insert(p->data, p->tail, val);
	//让队尾+1，并且判断该操作后是否会非法
	p->tail += 1;
	if (p->tail == p->size) {
		p->tail = 0;
	}
	//让count+1，表示队列含有数据个数+1
	p->count += 1;
	return 1;
}

//删除队尾的数据
int Delete(queue* p) {
	//判断队列中是否为空
	if (Empty(p)) {
		return 0;
	}
	//让队首向后一个，含有的数据-1
	p->head += 1;
	p->count -= 1;
	return 1;
}

//输出队首的数据
//假设存在一个函数Vector_Seek能能读取该数据
int Queue_Front(queue* p) {
	return Vector_Seek(p->data, p->head);
}
//定义一个函数用于释放队列的空间
void Queue_Free(queue* head) {
	if (head == NULL) {
		return;
	}
	free(head);
	return;
}