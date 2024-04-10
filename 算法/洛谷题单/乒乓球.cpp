#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	char p;
	vector<int> q1, q2;
	for (int i = 0; scanf("%c", &p) && p != 'E'; i++) {
		if (p == 'W') {
			q1.push_back(1);
			q2.push_back(1);
		}
		else if(p=='L') {
			q1.push_back(2);
			q2.push_back(2);
		}
	}
	int l = 0, r = 0;
	for (; !q1.empty();) {
		if (q1.front() == 1) {
			l++;
		}
		else {
			r++;
		}
		if ((l>=11 || r>=11) && abs(l - r) >= 2) {
			printf("%d:%d\n", l, r);
			l = 0, r = 0;
		}
		q1.erase(q1.begin());
	}
	printf("%d:%d\n", l, r);
	l = 0, r = 0;
	printf("\n");
	for (; !q2.empty();) {
		if (q2.front() == 1) {
			l++;
		}
		else {
			r++;
		}
		if ((l >= 21 || r >= 21) && abs(l - r) >= 2) {
			printf("%d:%d\n", l, r);
			l = 0, r = 0;
		}
		q2.erase(q2.begin());
	}
	printf("%d:%d\n", l, r);

	return 0;
}