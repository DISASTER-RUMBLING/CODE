#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;

string h;
int arr[105] = { 0 };

int main() {

	cin >> h;
	for (int i = 0; i < h.size(); i++) {
		if (h[i] == ')') {
			for (int j = i - 1; j >= 0; j--) {
				if (h[j] == '(' && !arr[j]) {
					arr[j] = 1;
					arr[i] = 1;
					break;
				}
				else if (h[j] == '[' && !arr[j]) {
					break;
				}
			}
		}
		else if (h[i] == ']') {
			for (int j = i - 1; j >= 0; j--) {
				if (h[j] == '[' && !arr[j]) {
					arr[j] = arr[i] = 1;
					break;
				}
				else if (h[j] == '(' && !arr[j]) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < h.size(); i++) {
		if (arr[i]) {
			printf("%c", h[i]);
		}
		else {
			if (h[i] == '(' || h[i] == ')') {
				printf("()");
			}
			else {
				printf("[]");
			}
		}
	}

	return 0;
}