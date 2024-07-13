#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int times;
	scanf("%d", &times);
	while (times--) {
		int res = 0, ans, n;
		scanf("%d%d", &ans, &n);
		int mx=0;
		for (int i = 0,nums; i < n; i++) {
			scanf("%d", &nums);
			if (mx == 0) {
				mx = nums;
			}
			else if (mx < nums) {
				res += (2 * mx) - 1;
				mx = nums;
			}
			else if (mx >= nums && nums != 1) {
				res += (nums * 2) - 1;
			}
			else {
				res += 1;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}