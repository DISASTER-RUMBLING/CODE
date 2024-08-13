#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<iostream>
#include<vector>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int nums, num;
		cin >> nums;
		vector<int> arr(nums);
		for (int i = 0,num; i < nums; i++) {
			cin >> arr[i];
		}
		cin >> num;
		while (num--) {
			map<int, char> mmp1;
			map<char, int> mmp2;
			string now;
			cin >> now;
			char p;
			int flag = 1;
			if (now.size() > nums || now.size()<nums) {
				cout << "NO" << endl;
			}
			else {
				for (int i = 0; i < nums; i++) {
					p = now[i];
					if (flag) {
						if (mmp1[arr[i]] == 0 && mmp2[p] == 0) {
							mmp1[arr[i]] = p;
							mmp2[p] = arr[i];
						}
						else {
							if (mmp1[arr[i]] != p || mmp2[p] != arr[i]) {
								cout << "NO" << endl;
								flag = 0;
								break;
							}
						}
					}
				}
				if (flag) {
					cout << "YES" << endl;
				}
			}
		}
	}

	return 0;
}