#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

struct Per {
	int year, month, day, n;
	string name;
}arr[101];

bool cmp(Per p1, Per p2) {
	if (p1.year != p2.year) {
		return p1.year < p2.year;
	}
	else {
		if (p1.month != p2.month) {
			return p1.month < p2.month;
		}
		else if (p1.day != p2.day) {
			return p1.day < p2.day;
		}
		else {
			return p1.n > p2.n;
		}
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].year >> arr[i].month >> arr[i].day;
		arr[i].n = i;
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i].name << endl;
	}

	return 0;
}