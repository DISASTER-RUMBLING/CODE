#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

bool Binary_Search(int* arr, int target, int tail) {
	tail--;
	int head = 0, mid = (head + tail) / 2;
	while (head <= tail) {
		if (arr[mid] == target) {
			return true;
		}
		if (arr[mid] > target) {
			head = mid + 1;
		}
		else {
			tail = mid - 1;
		}
		mid = (head + tail) / 2;
	}
	return false;
}