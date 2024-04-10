#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int w, n, time = 0;
	scanf("%d", &w);
	scanf("%d", &n);
	vector<int> arr;
	for (int i = 0,now; i < n; i++) {
		scanf("%d", &now);
		arr.push_back(now);
	}
	sort(arr.begin(), arr.end());
	int l = 0, r = n - 1;
	while (l < r) {
		if ((arr[l] + arr[r]) <= w) {
			l++;
			r--;
		}
		else {
			r--;
		}
		time++;
	}
	if (l == r) {
		time++;
	}
	printf("%d", time);

	return 0;

}