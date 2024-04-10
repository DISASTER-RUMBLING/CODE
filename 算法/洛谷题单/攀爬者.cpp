#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct site {
	int x, y, z;
}arr[50500];

bool cmp(site p1, site p2) {
	return p1.z < p2.z;
}

int main() {

	int n;
	float res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &arr[i].x, &arr[i].y, &arr[i].z);
		
	}
	sort(arr + 1, arr + n + 1, cmp);
	for (int i = 1; i <= (n - 1); i++) {
		res += sqrt(pow(arr[i].x - arr[i + 1].x, 2) + pow(arr[i].y - arr[i + 1].y, 2) + pow(arr[i].z - arr[i + 1].z, 2));
	}
	printf("%.3lf", res);

	return 0;
}