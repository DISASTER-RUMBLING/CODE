#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, h[305] = { 0 };
long long res = 0;

bool Cmp(int x, int y) {
	return x < y;
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	sort(h, h + n + 1, Cmp);
	int beg = 0, ed = n, flag = 1;
	//flag=1时为低往高跳，flag=0时为高往低跳
	while (beg < ed) {
		if (flag) {
			res += pow(h[ed] - h[beg], 2);
			beg++;
			flag = 0;
		}
		else {
			res += pow(h[ed] - h[beg], 2);
			ed--;
			flag = 1;
		}
	}
	printf("%lld", res);

	return 0;
}