#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int res = 0;

bool check(int* arr) {
	for (int i = 0; i <= 2; i++) {
		if (arr[i] + 1 == arr[i + 1] && arr[i + 1] + 1 == arr[i + 2]) {
			return true;
		}
	}
	return false;
}

int main() {

	for (int mon = 1; mon < 13; mon++) {
		for (int day = 1; day <= month[mon]; day++) {
			int arr[5] = { 2,mon / 10,mon % 10,day / 10,day % 10 };
			if (check(arr)) {
				res++;
			}
		}
	}
	printf("%d", res);

	return 0;
}