#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;


int main() {

	int n, s;
	char arr[245];
	cin >> arr;
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int j = 0;
		while (arr[j + 1] && arr[j] <= arr[j + 1]) {
			j++;
		}
		while (arr[j]) {
			arr[j] = arr[j + 1];
			j++;
		}
	}
	for (int i = 0, flag = 1; arr[i]; i++) {
		if (arr[i] == '0' && flag == 1) {
			continue;
		}
		printf("%c", arr[i]);
		flag = 0;
	}

	return 0;

}