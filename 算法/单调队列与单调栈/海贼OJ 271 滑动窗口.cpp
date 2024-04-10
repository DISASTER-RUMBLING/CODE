#define _CRT_SECURE_NO_WARNINGS
#include<deque>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	vector<int> arr(n), max;
	deque<int> p;
	for (int i = 0, j; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		while (!p.empty() && arr[p.back()] > arr[i]) {
			p.pop_back();
		}
		p.push_back(i);
		if ((i - p.front()) == k) {
			p.pop_front();
		}
		if (i + 1 < k) {
			continue;
		}
		if (i >= k) {
			printf(" ");
		}
		printf("%d", arr[p.front()]);
	}
	printf("\n");
	p.clear();
	for (int i = 0; i < n; i++) {
		while (!p.empty() && arr[p.back()] < arr[i]) {
			p.pop_back();
		}
		p.push_back(i);
		if ((i - p.front()) == k) {
			p.pop_front();
		}
		if (i + 1 < k) {
			continue;
		}
		if (i >= k) {
			printf(" ");
		}
		printf("%d", arr[p.front()]);
	}

	return 0;
}