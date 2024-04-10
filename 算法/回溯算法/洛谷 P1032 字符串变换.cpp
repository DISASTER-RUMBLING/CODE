#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

//main函数中while循环无法停止
unordered_map<string, int> dp;
int res = 100;

void Deep_Seek(string now, string tar, string* from, string* to, int step, int cnt) {
	dp[now] = step;
	if (step > 10) {
		return;
	}
	if (now == tar) {
		res = res > step ? step : res;
		return;
	}
	if (step + 1 > res) {
		return;
	}
	for (int i = 0; i < cnt; i++) {
		int pos = -1;
		pos = now.find(from[i]);
		while (pos != -1) {
			string change = now;
			change.erase(pos, from[i].size());
			change.insert(pos, to[i]);
			if (dp[change] >= (step + 1) && dp.find(change) != dp.end()) {
				continue;
			}
			Deep_Seek(change, tar, from, to, step + 1, cnt);
		}
	}
}

int main() {

	string begin, tar, form[10], to[10];
	cin >> begin >> tar;
	int cnt = 0;
	while (cin>>form[cnt]>>to[cnt] ) {
		cnt++;
	}
	Deep_Seek(begin, tar, form, to, 0, cnt);
	printf("%d", res);

	return 0;

}