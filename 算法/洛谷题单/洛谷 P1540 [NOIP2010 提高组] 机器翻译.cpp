#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

int m, n, times = 0;
bool use[1005] = { 0 };
queue<int> arr;

int main() {

	scanf("%d%d", &m, &n);
	for (int i = 0,j; i < n; i++) {
		scanf("%d", &j);
		if (!use[j]) {
			arr.push(j);
			use[j] = 1;
			times++;
			if (arr.size() > m) {
				use[arr.front()] = 0;
				arr.pop();
			}
		}
	}
	printf("%d", times);

	return 0;
}