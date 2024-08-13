#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int nums, flag = 1;
		cin >> nums;
		map<int, int> mmp;
		for (int i = 0, num; i < nums; i++) {
			cin >> num;
			mmp[num] = 1;
			if (flag && i) {
				if ((num - 1 > 0 && !mmp[num - 1]) && (num + 1 <= nums && !mmp[num + 1])) {
					cout << "NO" << endl;
					flag = 0;
				}
				else if ((num + 1 <= nums && !mmp[num + 1]) && num-1==0) {
					cout << "NO" << endl;
					flag = 0;
				}
				else if (num == nums && ((num - 1 > 0 && !mmp[num - 1]))) {
					cout << "NO" << endl;
					flag = 0;
				}
			}
		}
		if (flag) {
			cout << "YES" << endl;
		}
	}

	return 0;
}