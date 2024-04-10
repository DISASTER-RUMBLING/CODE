#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string, int> arr;
int n;

int main() {

	scanf("%d", &n);
	while (n--) {
		string h;
		cin >> h;
		arr.insert({ h,1 });
	}
	printf("%d", arr.size());

	return 0;
}