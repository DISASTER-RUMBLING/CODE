#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	string now;
	cin >> now;
	int r = now.size() - 1, l = 0, flag = 1;
	while (l < r) {
		if (now[l] > now[r]) {
			printf("1\n");
			flag = 0;
			break;
		}
		else if (now[l] < now[r]) {
			printf("-1\n");
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("0\n");
	}

	return 0;
}