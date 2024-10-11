#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	string num;
	cin >> num;
	int beg = 0, ed = num.size() - 1;
	while (num[beg] == num[ed] && beg < ed) {
		beg++;
		ed--;
	}
	if (beg >= ed) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}