#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int arr[10] = { 0 };
int n, times = 0;

struct node {
	int arr[10];
}arr1[100005];

void dfs(int deep, int sum) {
	if (deep==10) {
		if (sum == n) {
			node p;
			for (int i = 0; i < 10; i++) {
				p.arr[i] = arr[i];
			}
			arr1[times++] = p;
		}
		return;
	}
	for (int i = 1; i <= min(3, n - sum); i++) {
		arr[deep] = i;
		dfs(deep + 1, sum + i);
	}
	return;
}

int main() {

	
	scanf("%d", &n);
	dfs(0, 0);
	printf("%d\n", times);
	for (int i = 0; i < times; i++) {
		printf("%d %d %d %d %d %d %d %d %d %d\n", arr1[i].arr[0], arr1[i].arr[1], arr1[i].arr[2], arr1[i].arr[3], arr1[i].arr[4], arr1[i].arr[5], arr1[i].arr[6], arr1[i].arr[7], arr1[i].arr[8], arr1[i].arr[9]);
	}

	return 0;
}