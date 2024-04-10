#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct node {
	int beg, ed, times;
}arr[1000005];

int n;

bool Cmp(node p1, node p2) {
	if (p1.ed == p2.ed) {
		return p1.times < p2.times;
	}
	return p1.ed < p2.ed;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].beg, &arr[i].ed);
		arr[i].times = arr[i].ed - arr[i].beg;
	}
	sort(arr, arr + n, Cmp);
	int res = 1, now = arr[0].ed;
	for (int i = 1; i < n; i++) {
		if (arr[i].beg >= now) {
			now = arr[i].ed;
			res++;
		}
		continue;
	}
	printf("%d", res);

	return 0;
}