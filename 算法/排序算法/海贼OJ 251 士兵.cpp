#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int X, Y, costx = 0, costy = 0;
	sort(x.begin(), x.end());
	for (int i = 0; i < n; i++) {
		x[i] = x[i] - i;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	Y = y[n / 2], X = x[n / 2];
	for (int i = 0; i < n; i++) {
		costx += abs(x[i] - X);
		costy += abs(y[i] - Y);
	}
	printf("%d", costx + costy);

	return 0;
}