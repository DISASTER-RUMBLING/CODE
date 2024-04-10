#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

#define MAX_ 500000
int arr_[MAX_ + 5], tmp[MAX_ + 5];

int Merge_Sort(int* arr, int left, int right) {
	if (right - left <= 1) {
		return 0;
	}
	int mid = (right - left) / 2;
	int last = Merge_Sort(arr, left, mid) + Merge_Sort(arr, mid, right), now = 0;
	int p1 = left, p2 = mid, k = 0;
	while (p1 < mid || p2 < right) {
		if (p2 == right || (p1 < mid && arr[p1] <= arr[p2])) {
			tmp[k++] = arr[p1++];
		}
		else {
			tmp[k++] = arr[p2++];
			now += (mid - p1);
		}
	}
	for (int i = left; i < right; i++) {
		arr[i] = tmp[i - left];
	}
	return last + now;
}

void Solve(int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", arr_+i);
	}
	printf("%d", Merge_Sort(arr_, 0, n));
	return;
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		Solve(n);
	}

	return 0;
}