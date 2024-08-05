#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int num, res = 0;
		scanf("%d", &num);
		int arr[4] = { 0 };
		char p;
		getchar();
		for (int i = 0; i < (4 * num); i++) {
			scanf("%c", &p);
			if (p == '?') {
				continue;
			}
			if (arr[(int)(p - 'A')] < num) {
				res++;
			}
			arr[(int)(p - 'A')]++;
		}
		printf("%d\n", res);
	}

	return 0;
}