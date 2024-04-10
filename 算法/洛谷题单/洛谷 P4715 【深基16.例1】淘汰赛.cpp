 #define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

struct No {
	int num, no;
};

int arr1[300], arr2[300], n;
vector<No> arr;

int main() {

	scanf("%d", &n);
	for (int i = 1, j = 1 << n, num; i <= j; i++) {
		scanf("%d", &num);
		arr.push_back({ num,i });
	}
	while (arr.size() > 2) {
		for (int i = 0, j = 1 << (--n); i < j; i++) {
			arr.push_back(arr[i * 2].num > arr[i * 2 + 1].num ? arr[i * 2] : arr[i * 2 + 1]);
		}
		arr.erase(arr.begin(), arr.begin() + (1 << (n + 1)));
	}
	if (arr[0].num > arr[1].num) {
		cout << arr[1].no;
	}
	else {
		cout << arr[0].no;
	}

	return 0;
}