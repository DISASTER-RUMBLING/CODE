#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct per {
	int score, num;
}arr[5005];

bool cmp(per p1, per p2) {
	if (p1.score != p2.score) {
		return p1.score > p2.score;
	}
	return p1.num < p2.num;
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].num, &arr[i].score);
	}
	sort(arr, arr + n, cmp);
	int num = 0;
	int score = arr[(int)floor(m*1.5)-1].score;
	while (arr[num+1].score >= score) {
		num++;
	}
	printf("%d %d\n", arr[num].score, num + 1);
	for (int i = 0; i <= num; i++) {
		printf("%d %d\n", arr[i].num, arr[i].score);
	}

	return 0;
}