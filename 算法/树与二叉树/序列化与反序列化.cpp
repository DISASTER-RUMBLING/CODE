#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree {
	int data;
	tree* kid, * bro;
}tree;

//序列化指将二叉树转化为广义表的过程
//反序列化指将广义表转化为二叉树的过程


//序列化
char buff[1000];
int len;

void Seralize(tree* p) {
	if (p==NULL) {
		return;
	}
	len += sprintf(buff + len, "%d", p->data);
	if (p->bro == NULL && p->kid == NULL) {
		return;
	}
	buff[len++] = '(';
	Seralize(p->kid);
	if (p->bro) {
		buff[len++] = ',';
		Seralize(p->bro);
	}
	buff[len++] = ')';
	return;
}

void _Seralize(tree* p) {
	memset(buff, 0, sizeof(buff));
	len = 0;
	Seralize(p);
	return;
}

//反序列化
//假设存在一个函数为Init()为开辟一个空间给二叉树的节点
tree* Init(int val);

tree* Deseralize(char buff[], int len) {
	int scode = 0, flag = 0, top = -1;
	tree* stack[1000] = { NULL }, * p = NULL, * root = NULL;
	for (int i = 0; buff[i]; i++) {
		switch (scode) {
		case 0: {
			if (buff[i] <= '9' && buff[i] > '0') {
				scode = 1;
			}
			else if (buff[i] == '(') {
				scode = 2;
			}
			else if (buff[i] == ',') {
				scode = 3;
			}
			else {
				scode = 4;
			}
			i--;
			break;
		}
		case 1: {
			int key = 0;
			while (buff[i] >= '0' && buff[i] <= '9') {
				key = key * 10 + buff[i] - '0';
			}
			p = Init(key);
			if(top > -1) {
				if (flag == 1) {
					stack[top]->kid = p;
				}
				else {
					stack[top]->bro = p;
				}
			}
			scode = 0;
			i--;
			break;
		}
		case 2: {
			flag = 1;
			stack[++top] = p;
			scode = 0;
			break;
		}
		case 3: {
			flag = 2;
			break;
		}
		case 4: {
			root = stack[top--];
			break;
		}
		}
		i--;
	}
	return root;
}
