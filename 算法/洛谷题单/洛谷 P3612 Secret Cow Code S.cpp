#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

string now;
long long times, len, n_len;

int main() {

	cin >> now >> times;
	n_len = len = now.size();
	while (n_len < times) {
		n_len <<= 1;
	}
	while (n_len != len) {
		n_len >>= 1;
		times = (times > n_len) ? ((times == n_len + 1) ? n_len : times - n_len - 1) : times;
	}
	cout << now[times - 1];

	return 0;
}