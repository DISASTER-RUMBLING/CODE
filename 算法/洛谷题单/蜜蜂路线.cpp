#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

long long beg, ed;
long long arr[1005][1005] = {0};

//xΪn
void Sum(int x) {
	for (int i = 0,flag=0; i < 1005; i++) {
		arr[x][i] = (arr[x - 1][i] + arr[x - 2][i] + flag);
		flag = (arr[x][i] / 10);
		arr[x][i] %= 10;
	}
}

int main() {

	scanf("%lld%lld", &beg, &ed);
	arr[beg][0] = 1;
	for (long long i = beg+1; i <= ed; i++) {
		if (i == (beg + 1)) {
			arr[i][0] = arr[beg][0];
			continue;
		}
		Sum(i);
	}
	for (int i = 1004,flag=1; i >= 0; i--) {
		if (flag && !arr[ed][i]) {
			continue;
		}
		printf("%lld", arr[ed][i]);
		flag = 0;
	}

	return 0;
}