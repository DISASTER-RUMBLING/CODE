#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int n, m, arr[100005] = { 0 };
vector<int> que;

int main() {

	scanf("%d", &n);
	que.push_back(1);
	for (int i = 2,j,k; i <= n; i++) {
		scanf("%d%d", &j, &k);
		//²åÈë×ó±ß
		auto x = find(que.begin(), que.end(), j);
		if (k == 0) {
			que.insert(x, i);
		}
		//²åÈëÓÒ±ß
		else  if (k == 1) {
			que.insert(x + 1, i);
		}
	}
	scanf("%d", &m);
	while (m--) {
		int j;
		scanf("%d", &j);
		if (arr[j] == 0) {
			arr[j] = 1;
			auto x = find(que.begin(), que.end(), j);
			que.erase(x);
		}
	}
	for (auto x : que) {
		printf("%d ", x);
	}

	return 0;
}