#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const long long num = 1000005;
long long n;
//arr[n][0]表示涂满面积为n*2面积的方法数，arr[n][1]表示涂满(n*2)+1面积的方法数
int arr[num][2] = { 0 };

int main() {

	scanf("%lld", &n);
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (long long i = 2; i <= n; i++) {
		arr[i][0] += (((arr[i - 1][0] + arr[i - 2][0] % 10000) + (2 * arr[i - 2][1] % 10000)) % 10000);
		arr[i][1] += ((arr[i - 1][0] + arr[i - 1][1]) % 10000);
	}
	printf("%d", arr[n][0]);

	return 0;
}