#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

int main() {

	string num;
	cin >> num;
	int sz = num.size();
	for (int i = 0; i < sz; i++) {
		arr.push_back(num[i] - '0');
	}
	while (!arr.empty()) {
		int flag = 0, l_flag = 0;
		for (int i = 0; i < sz; i++) {
			printf("%d", arr[i]);
			flag = (arr[i]+ l_flag*10) % 2;
			arr[i] =((arr[i]+ l_flag*10) / 2);
			l_flag = flag;
		}
		printf(" ");
		while (!arr.empty() && *arr.begin() == 0) {
			arr.erase(arr.begin());
			sz--;
		}
	}

	return 0;
}