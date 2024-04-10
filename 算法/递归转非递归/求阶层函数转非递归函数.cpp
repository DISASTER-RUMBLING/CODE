#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<malloc.h>
#include<stack>


//µÝ¹éº¯ÊýÇó½×²ã
int F(int n) {
	if (n == 1) {
		return 1;
	}
	return (n * F(n - 1));
}

 //·ÇµÝ¹éº¯ÊýÇó½×²ã
struct data {
	int val, ret, code;
	int* pre_ret;
};

data* Data(int val, int* pre_ret) {
	data* p = (data*)malloc(sizeof(data));
	p->val = val;
	p->pre_ret = pre_ret;
	p->code = 0;
	return p;
}

int Non_F(int n) {
	std::stack<data*> s;
	int res;
	data* p = Data(n, &res);
	s.push(p);
	while (!s.empty()) {
		data* q = s.top();
		switch (q->code) {
		case 0: {
			if (q->val == 1) {
				*(q->pre_ret) = 1;
				s.pop();
			}
			else {
				q->code = 1;
			}
		}break;
		case 1: {
			data* j = Data(n - 1, q.pre_ret);
			q->code = 2;
			s.push(j);
		}break;
		case 2: {
			*(q->pre_ret) = q->ret * q->val;
			s.pop();
		}break;
		}
	}
	return res;
}
