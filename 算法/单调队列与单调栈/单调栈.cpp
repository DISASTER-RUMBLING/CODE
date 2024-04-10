#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<malloc.h>
#include<vector>
using namespace std;

//单调递增
//返回的数列是在第i个位置以左（i>0）最近的比他小的值
int* Left_Monotonic_Stack(vector<int> arr) {
	stack<int> p;
	int* q = (int*)malloc(sizeof(int) * arr.size());
	for (int i = arr.size() - 1; i >= 0; i--) {
		while (!p.empty() && arr[p.top()] > arr[i]) {
			q[p.top()] = i;
			p.pop();
		}
		p.push(i);
	}
	return q;
}

//返回的数列是在第i个位置以右（i>0）最近的比他小的值
int* Right_Monotonic_Stack(vector<int> arr) {
	stack<int> p;
	int* q = (int*)malloc(sizeof(int) * arr.size());
	for (int i = 0; i < arr.size(); i++) {
		while (!p.empty() && arr[p.top()] > arr[i]) {
			q[p.top()] = i;
			p.pop();
		}
		p.push(i);
	}
	return q;
}