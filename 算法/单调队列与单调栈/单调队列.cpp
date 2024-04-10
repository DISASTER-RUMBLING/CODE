#define _CRT_SECURE_NO_WARNINGS
#include<deque>
#include<vector>
#include<malloc.h>
using namespace std;

//假设k为窗口长度
//假设是递增序列
int* Monotonic_Queue(vector<int> arr, int k) {
	int n = arr.size();
	deque<int> p;
	int* res = (int*)malloc(sizeof(int) * n), ans = 0;
	for (int i = 0; i < n; i++) {
		while (!p.empty() && arr[p.back()] > arr[i]) {
			p.pop_back();
		}
		p.push_back(i);
		if ((i - p.back()) == k) {
			p.pop_front();
		}
		res[ans++] = arr[p.front()];
	}
	return res;
}