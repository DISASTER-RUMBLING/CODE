#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		string now;
		cin >> now;
		if (now.size()>=3 && now[0] == '1' && now[1] == '0') {
			if ((now.size() == 3 && now[2] >= '0' && now[2] < '2') || now[2]=='0') {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}