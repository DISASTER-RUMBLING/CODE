#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>

using namespace std;

stack<int> arr;

int main() {

	char p;
	int now = 0;
	do {
		scanf("%c", &p);
		if (p >= '0' && p <= '9') {
			now = (now * 10) + (p - '0');
		}
		else if (p == '.') {
			arr.push(now);
			now = 0;
		}
		else if (p == '+' || p == '-' || p == '*' || p == '/') {
			int x = arr.top();
			arr.pop();
			int y = arr.top();
			arr.pop();
			if (p == '+') {
				arr.push(x + y);
			}
			else if (p == '-') {
				arr.push(y - x);
			}
			else if (p == '/') {
				arr.push(y / x);
			}
			else if (p == '*') {
				arr.push(y * x);
			}
		}
	} 
	while (p != '@');
	printf("%d", arr.top());

	return 0;
}