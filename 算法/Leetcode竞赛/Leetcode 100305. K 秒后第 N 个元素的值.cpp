#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
	int valueAfterKSeconds(int n, int k) {
		vector<int> arr(n);
		int mod = 1e9 + 7;
		for (int i = 0; i < n; i++) {
			arr[i] = 1;
		}
		for (int i = 0; i < k; i++) {
			for (int j = 1; j < n; j++) {
				arr[j] = (arr[j] + arr[j - 1]) % mod;
			}
		}
		return arr[n - 1] % (mod);
	}
};