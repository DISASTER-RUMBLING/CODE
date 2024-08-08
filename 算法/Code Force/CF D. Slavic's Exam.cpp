#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {

	int times;
	cin >> times;
	while (times--) {
		string s, t;
		cin >> s;
		cin >> t;
		int szs = s.size(), szt = t.size(), now = 0;
		for (int i = 0; i < szs; i++) {
			if (s[i] == '?' || (now < szt && s[i] == t[now])) {
				if (now < szt) {
					s[i] = t[now];
				}
				else {
					s[i] = s[i - 1];
				}
				now++;
			}
		}
		if (now >= szt) {
			cout << "YES" << endl << s << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}