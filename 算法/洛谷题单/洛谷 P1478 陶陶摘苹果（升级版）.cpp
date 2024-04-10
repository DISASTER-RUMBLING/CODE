#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

struct node {
	int h, x;
}arr[5005];

int n, s, a, b, res = 0;

bool Cmp(node p1, node p2) {
	if (p1.x == p2.x) {
		return p1.h < p2.h;
	}
	return p1.x < p2.x;
}

int main() {

	scanf("%d%d", &n, &s);
	scanf("%d%d", &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].h, &arr[i].x);
	}
	sort(arr, arr + n, Cmp);
	int now = 0;
	while (s > 0 && now < n) {
		if (arr[now].h <= (a + b) && s >= arr[now].x) {
			s -= arr[now].x;
			res++;
		}
		now++;
	}
	printf("%d", res);

	return 0;
}