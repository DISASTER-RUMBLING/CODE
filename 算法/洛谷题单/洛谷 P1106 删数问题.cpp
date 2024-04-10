#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

char arr[255] = { 0 };
int n;

int main() {

	scanf("%s", &arr);
	getchar();
	scanf("%d", &n);
	int len = 0;
	while (arr[len] != '\0') {
		len++;
	}
	while (n--) {
		int now = 0;
		for (int i = 1; i < len; i++) {
			if (arr[i] >= arr[i - 1]) {
				now = i;
			}
			else {
				break;
			}
		}
		for (int i = now; i < len; i++) {
			arr[i] = arr[i + 1];
		}
		len--;
		while (arr[0] == '0') {
			for (int i = 0; i < len; i++) {
				arr[i] = arr[i + 1];
			}
			len--;
		}
	}
	int now = 0, flag = 1;
	while (arr[now] != '\0') {
		printf("%c", arr[now++]);
		flag = 0;
	}
	if (flag) {
		printf("0");
	}

	return 0;
}