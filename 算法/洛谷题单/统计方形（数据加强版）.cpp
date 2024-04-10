#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {

	long long n, m;
	scanf("%lld%lld", &n, &m);
	long long a = n, b = m, zheng = n * m;
	while (a != 0 && b != 0) {
		a--;
		b--;
		zheng += (a * b);
	}
	printf("%lld %lld", zheng, (m + 1) * (n + 1) * n * m / 4 - zheng);

	return 0;
}