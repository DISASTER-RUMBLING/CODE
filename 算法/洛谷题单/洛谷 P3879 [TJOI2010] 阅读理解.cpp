#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct node {
	int han, num;
};

int n, lon;
string now;
map<string, vector<int>> arr;

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &lon);
		while (lon--) {
			cin >> now;
			if (find(arr[now].begin(), arr[now].end(), i) == arr[now].end()) {
				arr[now].push_back(i);
			}
		}
	}
	scanf("%d", &n);
	while (n--) {
		cin >> now;
		auto x = arr[now].begin();
		while (x != arr[now].end()) {
			printf("%d ", *x);
			x++;
		}
		printf("\n");
	}

	return 0;
}