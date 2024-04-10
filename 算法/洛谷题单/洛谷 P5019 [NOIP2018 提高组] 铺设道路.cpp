#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int n, num, times = 0, l_num = 0;

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (l_num < num) {
			times += (num - l_num);
		}
		l_num = num;
	}
	printf("%d", times);

	return 0;
}