#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		int a1, a2, b1, b2, res = 0;
		cin >> a1 >> a2 >> b1 >> b2;
		if (a1 > b1) {
			if (a2 >= b2) {
				res++;
			}
		}
		else if (a1 == b1 && a2>b2) {
			res++;
		}
		if (a1 > b2) {
			if (a2 >= b1) {
				res++;
			}
		}
		else if (a1 == b2 && a2 > b1) {
			res++;
		}
		if (a2 > b1) {
			if (a1 >= b2) {
				res++;
			}
		}
		else if (a2 == b1 && a1 > b2) {
			res++;
		}
		if (a2 > b2) {
			if (a1 >= b1) {
				res++;
			}
		}
		else if (a2 == b2 && a1 > b1) {
			res++;
		}
		cout << res << endl;
	}

	return 0;
}