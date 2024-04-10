#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct per {
	int s1, s2, s3, sum, num;
}arr[305];

bool cmp(per p1, per p2) {
	if (p1.sum != p2.sum) {
		return p1.sum > p2.sum;
	}
	else {
		if (p1.s1 != p2.s1) {
			return p1.s1 > p2.s1;
		}
		else {
			return p1.num < p2.num;
		}
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &arr[i].s1, &arr[i].s2, &arr[i].s3);
		arr[i].sum = (arr[i].s1 + arr[i].s2 + arr[i].s3);
		arr[i].num = i;
	}
	sort(arr + 1, arr + n + 1, cmp);
	for (int i = 1; i < 6; i++) {
		printf("%d %d\n", arr[i].num, arr[i].sum);
	}

	return 0;
}
