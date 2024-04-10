#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct per {
	int num;
	string p;
}arr[25];

bool cmp(per p1, per p2) {
	if (p1.p.length() != p2.p.length()) {
		return p1.p.length() > p2.p.length();
	}
	else {
		int i = 0;
		while (p1.p[i] == p2.p[i]) {
			i++;
		}
		return p1.p[i] > p2.p[i];
	}
}

int main(){

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].p;
		arr[i].num = i;
	}
	sort(arr + 1, arr + n + 1, cmp);
	printf("%d\n", arr[1].num);
	cout << arr[1].p;

	return 0;
}