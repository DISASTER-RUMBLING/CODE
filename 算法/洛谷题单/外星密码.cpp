#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

string Str() {
	int times;
	string now, res;
	char p;
	while (cin>>p) {
		if (p == '[') {
			cin >> times;
			now = Str();
			while (times--) {
				res += now;
			}
		}
		else if (p == ']') {
			return res;
		}
		else {
			res += p;
		}
	}
	return res;
}

int main() {

	cout << Str();

	return 0;
}