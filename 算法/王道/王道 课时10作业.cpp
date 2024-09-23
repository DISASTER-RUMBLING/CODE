#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int num[10] = { 1,2,3 };
	int nums, sz = 3;
	scanf("%d", &nums);
	for (int i = 2; i >= 1; i--) {
		num[i] = num[i + 1];
	}
	num[1] = nums;
	sz++;
	for (int i = 0; i < sz; i++) {
		printf("  %d ", num[i]);
	}
	printf("\n");
	scanf("%d", &nums);
	if (sz < nums) {
		printf("false");
	}
	else {
		for (int i = 0; i < sz; i++) {
			if (nums != i) {
				printf("  %d ", num[i]);
			}
		}
	}
	printf("\n");

	return 0;
}