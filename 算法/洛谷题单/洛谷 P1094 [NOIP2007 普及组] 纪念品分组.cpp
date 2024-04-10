#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int ed, mx, arr[30005] = { 0 }, res = 0, beg = 0;

int main() {

	scanf("%d", &mx);
	scanf("%d", &ed);
	for (int i = 0; i < ed; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + ed);
	ed--;
	while (beg <= ed) {
		if (arr[beg] + arr[ed] <= mx) {
			res++;
			beg++, ed--;
		}
		else {
			ed--;
			res++;
		}
	}
	printf("%d", res);

	return 0;
}