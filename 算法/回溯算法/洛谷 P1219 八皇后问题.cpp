#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

#define MARK(n) ( ( 1 << ( (n) + 1 ) ) - 2 )

int print = 3;
int arr[20];
unordered_map<int, int> ind;

void Printf(int n) {
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
	print--;
	return;
}

int Eight_Queue_Question(int x, int y, int left, int right, int n) {
	if (x > n) {
		if (print) {
			Printf(n);
		}
		return 1;
	}
	int ans = 0;
	for (int i = y; i; i -= (i & (-i))) {
		int j = ind[(i & (-i))];
		if ((left & (1 << (x + j - 1))) && (right & (1 << (x - j + n)))) {
			arr[x] = j;
			ans += Eight_Queue_Question(x + 1, y ^ (1 << j), left ^ (1 << (x + j - 1)), right ^ (1 << (x - j + n)), n);
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	print = 3;
	for (int i = 0; i < 2 * n; i++) {
		ind[1 << i] = i;
	}
	int res = Eight_Queue_Question(1, MARK(n), MARK(2 * n - 1), MARK(2 * n - 1), n);
	printf("%d", res);

	return 0;
}