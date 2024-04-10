#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
using namespace std;

bool Prime_Num(int sum) {
	for (int i = 2; (i * i) <= sum; i++) {
		if (sum % i == 0) {
			return false;
		}
	}
	return true;
}

//now表示已经选了几个数，n表示可选数字的个数，k表示最多选多少个数字，sum表示选的数字之和
long long Choice_Num(int now, int ind, int n, int k, int sum, vector<int>res) {
	if (now == k) {
		if (Prime_Num(sum)) {
			return 1;
		}
		return 0;
	}
	long long ans = 0;
	for (int i = ind; i <= n; i++) {
		ans += Choice_Num(now + 1, i + 1, n, k, sum + res[i], res);
	}
	return ans;
}

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &res[i]);
	}
	printf("%lld", Choice_Num(0, 1, n, k, 0, res));

	return 0;
}