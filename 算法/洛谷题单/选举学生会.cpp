#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int num[20000001];

//void Swap(int* num1, int* num2) {
//	int tmp = *num1;
//	num1 = num2;
//	*num2 = tmp;
//	return;
//}
//
//void Quick_Sort(int* arr, int begin, int end) {
//	if ((end - begin) < 2) {
//		if ((end - begin) == 1) {
//			Swap(&arr[begin], &arr[end]);
//		}
//		return;
//	}
//	int l = begin + 1, r = end, now = begin;
//	while (l < r) {
//		while (arr[now] < arr[r] && l < r) {
//			r--;
//		}
//		if (l < r) {
//			Swap(&arr[now], &arr[r]);
//		}
//		now = r;
//		while (arr[l] < arr[now] && l < r) {
//			l++;
//		}
//		if (l < r) {
//			Swap(&arr[now], &arr[l]);
//		}
//		now = l;
//	}
//	Quick_Sort(arr, begin, l);
//	Quick_Sort(arr, l + 1, end);
//	return;
//}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num[i]);
	}
	sort(&num[0], &num[m]);
	for (int i = 0; i < m; i++) {
		if (i) {
			printf(" ");
		}
		printf("%d", num[i]);
	}


	return 0;
}