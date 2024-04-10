#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main() {
	int n;
	int arr[45][45] = { 0 };
	scanf("%d", &n);
	int x = (n / 2) + 1, y = 1;
	arr[y][x] = 1;
	int max = n * n;
	for (int i = 2; i <= max; i++) {
		if (y == 1 && x != n) {
			y = n;
			x++;
		}
		else if (x == n && y != 1) {
			y -= 1;
			x = 1;
		}
		else if (x == n && y == 1) {
			y++;
		}
		else if (y != 1 && x != n) {
			if (arr[y - 1][x + 1] == 0) {
				y -= 1;
				x += 1;
			}
			else {
				y++;
			}
		}
		arr[y][x] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j-1) {
				printf(" ");
			}
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}