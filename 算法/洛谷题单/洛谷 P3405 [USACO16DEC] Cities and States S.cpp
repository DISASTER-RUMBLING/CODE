#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

map<int, int> arr[100005];
int n, x, y, res = 0;

int main() {

	scanf("%d", &n);
	while (n--) {
		string h1, h2;
		cin >> h1;
		cin >> h2;
		x = h1[0] * 26 + h1[1];
		y = h2[0] * 26 + h2[1];
		res += arr[y][x];
		if (y == x) {
			res -= arr[x][y];
		}
		arr[x][y]++;
	}
	printf("%d", res);

	return 0;
}