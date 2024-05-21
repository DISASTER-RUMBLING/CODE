#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>

using namespace std;

//假定是大根堆
struct Heap
{
	int* _a;
	int _size;
	int _capacity;
};

Heap* Init_Heap() {
	Heap* p = (Heap*)malloc(sizeof(Heap));
	p->_a = (int*)malloc(sizeof(int) * 4);
	p->_capacity = 4;
	p->_size = -1;
	return p;
}

void Swap(int* x, int* y) {
	int tmp = *x;
	x = y;
	*y = tmp;
	return;
}

void Adjust_Upword(Heap* p) {
	for (int i = p->_size - 1; i > 0; i--) {
		if (p->_a[i] > p->_a[(i - 1) / 2]) {
			Swap(p->_a + i, p->_a + (i - 1) / 2);
		}
	}
	return;
}

// 堆的插入
void HeapPush(Heap* hp, int x) {
	if (hp == nullptr) {
		return;
	}
	if ((hp->_size + 1) == hp->_capacity) {
		hp->_a = (int*)realloc(hp->_a, sizeof(int) * 2 * hp->_capacity);
		hp->_capacity *= 2;
	}
	hp->_a[hp->_size] = x;
	Adjust_Upword(hp);
	hp->_size++;
	return;
}

void Adjust_Downward(Heap* p) {
	int now = 0;
	while (now < p->_size) {
		int tmp = p->_a[(now * 2) + 1] > p->_a[(now + 1) * 2] ? (now * 2) + 1 : (now + 1) * 2;
		if (tmp < p->_size) {
			Swap(p->_a + now, p->_a + tmp);
		}
		now = tmp;
	}
	return;
}

// 堆的删除
void HeapPop(Heap* hp) {
	hp->_a[0] = 0;
	Adjust_Upword(hp);
	hp->_size--;
	return;
}

// 取堆顶的数据
int Heap_Top(Heap* hp) {
	if (hp->_size > 0) {
		return hp->_a[0];
	}
}

// 堆的数据个数
int Heap_Size(Heap* hp) {
	return hp->_size + 1;
}

// 堆的判空
int HeapEmpty(Heap* hp) {
	return hp->_size == -1 ? 0 : 1;
}

void Heap_Free(Heap* p) {
	if (p == nullptr) {
		return;
	}
	if (p->_a != nullptr) {
		free(p->_a);
		p->_a = nullptr;
	}
	free(p);
	p = nullptr;
	return;
}