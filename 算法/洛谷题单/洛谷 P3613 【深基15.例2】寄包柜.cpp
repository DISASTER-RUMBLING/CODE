#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>

using namespace std;

int n, q;
map<long long, long long> arr;

int main() {

	scanf("%d%d", &n, &q);
	while (q--) {
		int num, j, k, l;
		scanf("%d%d%d", &num, &j, &k);
		if (num == 1) {
			scanf("%d", &l);
			if (l == 0) {
				arr[j * 100000 + k] = 0;
			}
			else {
				arr[j * 100000 + k] = l;
			}
		}
		else if (num == 2) {
			cout << arr[j * 100000 + k] << endl;
		}
	}

	return 0;
}