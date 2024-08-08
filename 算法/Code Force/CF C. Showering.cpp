#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int n, s, m, last = 0, flag = 1;
		cin >> n >> s >> m;
		for (int i = 0,start,end; i < n; i++) {
			cin >> start >> end;
			if (start - last >= s && flag) {
				cout << "YES" << endl;
				flag = 0;
			}
			last = end;
		}
		if (m - last >= s && flag) {
			cout << "YES" << endl;
			flag = 0;
		}
		if (flag) {
			cout << "NO" << endl;
		}
	}

	return 0;
}