#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
using namespace std;

#define MAX 0x3f3f3f3f

long long result(string s, long long l, long long r) {
	long long pos = -1, pri =MAX-1, tmp_pri=0, cur_pri = MAX-1, flag = 1;
	for (int i = l; i < r; i++) {
		cur_pri = MAX;
		switch (s[i]) {
			case '(':
				tmp_pri += 100;
				break;
			case ')':
				tmp_pri -= 100;
				break;
			case '+':
			case '-':
				cur_pri = tmp_pri + 1;
				break;
			case '*':
			case '/':
				cur_pri = tmp_pri + 2;
				break;
			case '^':
				cur_pri = tmp_pri + 3;
				break;
		}
		if (pri >= cur_pri) {
			pri = cur_pri;
			pos = i;
		}
	}
	if (pos == -1) {
		if (s[0] == '-') {
			flag = -1;
		}
		long long num = 0;
		for (int i = l; i < r; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				num = (10 * num) + (s[i] - '0');
			}
		}
		return flag * num;
	}
	else {
		long long a = result(s, l, pos);
		long long b = result(s, pos + 1, r);
		switch (s[pos]) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '^':
			return ((int)pow(a, b));
		}
	}
}

int main() {
	string s;
	cin >> s;
	cout << result(s, 0, s.size()) << endl;

	return 0;
}
