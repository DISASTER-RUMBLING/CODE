#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

//m表示重量，v表示价值，rat表示v/m
struct node {
	int m, v;
	double rat;
}arr[105] = { 0 };

int n, t;
float res = 0;

bool Cmp(node p1, node p2) {
	return p1.rat > p2.rat;
}

int main() {

	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		node p;
		scanf("%d%d",&arr[i].m, &arr[i].v);
		arr[i].rat = (double)arr[i].v / (double)arr[i].m;
	}
	sort(arr+1, arr+n+1, Cmp);
	int spt = t, i = 1;
	while (spt > 0) {
		if (i > n) {
			break;
		}
		if (arr[i].m <= spt) {
			res += (float)arr[i].v;
			spt -= arr[i].m;
			i++;
		}
		else {
			float ra = (float)(spt / (float)arr[i].m);
			res += ra * arr[i].v;
			spt -= ra * arr[i].m;
			i++;
		}
	}
	printf("%.2f", res);

	return 0;
}