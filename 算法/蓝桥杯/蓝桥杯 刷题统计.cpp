#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

#define ll long long

ll work, rest, week, tar, res = 0;

int main() {

	scanf("%lld%lld%lld", &work, &rest, &tar);
	week = work * 5 + rest * 2;
	res += ((tar / week) * 7);
	tar -= (res / 7) * week;
	int day = 1;
	while (tar > 0) {
		if (day < 6) {
			tar -= work;
		}
		else {
			tar -= rest;
		}
		day++;
		res++;
		if (day > 7) {
			day = 1;
		}
	}
	printf("%lld", res);

	return 0;
}