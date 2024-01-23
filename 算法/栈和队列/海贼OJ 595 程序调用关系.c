#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	//定义俩整形用于存储num将输入几个指令，now现在指向的位置
	int num, now = 0;
	//定义一个指针字符数组，用于储存字符串
	char* f[100000];
	//输入即将要输入几个指令
	scanf("%d", &num);
	//循环录入指令，若输入为return，则删除该指针和上一个指针
	for (int i = 0; i < num; i++) {
		char* p = (char*)malloc(111 * sizeof(char));
		scanf("%s", p);
		f[now] = p;
		if (strcmp(f[now],"return") == 0) {
			free(p);
			free(f[now - 1]);
			f[now] = NULL;
			p = NULL;
			now--;
			continue;
		}
		now++;
	}
	//开辟一个空间，存储目标函数
	char* target = (char*)malloc(111 * sizeof(char));
	//输入目标函数
	scanf("%s", target);
	//循环循环寻找该函数
	for (int i = 0; i < now; i++) {
		//判断是否为目标函数，若是则记录当前的地址，并且跳出循环
		if (strcmp(f[i],target) == 0) {
			now = i;
			break;
		}
		//当走到最后一个函数时，当仍然不是目标函数，则输出NOT REFERENCED
		if (i == (now - 1)) {
			printf("NOT REFERENCED\n");
			return 0;
		}
	}
	//循环输出函数路径
	for (int i = 0; i < now + 1; i++) {
		printf("%s", (f[i]));
		if (i != now) {
			printf("->");
		}
	}

	return 0;
}