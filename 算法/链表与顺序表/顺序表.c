#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//结构定义
typedef struct vector {
	int size, count;
	int* data;
}vector;

vector* GetNewVector(int n) {
	//开辟一个空间给vector
	vector* p = (vector*)malloc(sizeof(vector));
	p->size = n;
	p->count = 0;
	//开辟一个大小为n个整形的空间
	p->data = (int*)malloc(sizeof(int) * n);
	//返回指向空间p的指针
	return p;
}

//实现扩容操作
int expand(vector* v) {
	//使用realloc函数扩容
	int *p = (int*)realloc((int*)v->data, sizeof(int) * v->size * 2);
	//判断是否扩容成功
	if (p == NULL) {
		return 0;
	}
	//成功后将新地址覆盖掉旧地址并且返回成功信息
	v->data = p;
	v->size *= 2;
	return 1;
}

//实现插入操作
int Insert(vector* v, int pos, int val) {
	//判断顺序表是否满了，是否扩容成功
	if (v->size == v->count && !expand(v) ) {
		return 0;
	}
	//判断插入位置是否非法
	if (pos > v->size || pos < 0) {
		return 0;
	}
	//将插入位置及其后的空间中的数据往后移动一个符号单位
	for (int i = v->count - 1; i >= pos; i--) {
		v->data[i + 1] = v->data[i];
	}
	//在该位置插入该数字
	v->data[pos] = val;
	//顺序表中的含有的数字+1
	v->count += 1;
	//返回成功插入的提示
	return 1;
}

int PushFront(vector* v, int val) {
	if (v == NULL) {
		return 0;
	}
	return Insert(v, 0, val);
}

int PushBack(vector* v, int val) {
	if (v == NULL) {
		return 0;
	}
	return Insert(v, v->count, val);
}

//实现删除操作
int Delete(vector* v, int pos) {
	//判断删除位置是否非法
	if (pos >= v->size || pos < 0) {
		return 0;
	}
	//将要删除的位置后的数据都往前移动一个字符单位
	for (int i = pos; i < v->count; i++) {
		v->data[i - 1] = v->data[i];
	}
	//顺序表中含有的数字-1
	v->count -= 1;
	//返回删除成功的提示
	return 1;
}

int PopFront(vector* v) {
	if (v == NULL || v->count == 0) {
		return 0;
	}
	return Delete(v, 0);
}

int PopBack(vector* v) {
	if (v == NULL || v->count == 0) {
		return 0;
	}
	return Delete(v, v->count);
}

//释放空间
void Free(vector* v) {
	if (v == NULL) {
		return;
	}
	free(v->data);
	free(v);
	return;
}

void Print(vector* v) {
	if (v->count == 0 || v == NULL) {
		return;
	}
	for (int i = 0; i < v->count; i++) {
		printf("%d->", v->data[i]);
	}
	printf("\n");
	return;
}
