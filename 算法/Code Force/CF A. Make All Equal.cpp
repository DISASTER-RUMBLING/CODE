#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int num;
		cin >> num;
		map<int, int> mmp;
		int res = num;
		for (int i = 0,nums; i < num; i++) {
			cin >> nums;
			mmp[nums] += 1;
			res = min(res, num - mmp[nums]);
		}
		cout << res << endl;
	}

	return 0;
}