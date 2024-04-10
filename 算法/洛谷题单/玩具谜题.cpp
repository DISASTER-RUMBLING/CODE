#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int head;
	string name;
};

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	Node arr[10005];
	for (int i = 0; i<n; i++) {
		//第一个是圈内12点位置的，即最后一个
		cin >> arr[i].head >> arr[i].name;
		//head 0为朝内
		//     1为朝外
	}
	int now = 0;
	for (int i = 0, step, dire; i < m; i++) {
		scanf("%d%d", &dire, &step);
		//dire 0为向左
		//     1为向右
		if (arr[now].head == 0 && dire == 0) {
			now = (now - step + n) % n;
		}
		else if (arr[now].head == 0 && dire == 1) {
			now = (now + step) % n;
		}
		else if (arr[now].head == 1 && dire == 0) {
			now = (now + step) % n;
		}
		else {
			now = (now - step + n) % n;
		}
	}
	cout << arr[now].name;

	return 0;
}