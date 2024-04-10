#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

struct node {
	ll fir, num;
};

ll n, num, tar;
vector<node> arr;

bool cmp(node x, node y) {
	return x.num < y.num;
}

int main() {

	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &num);
		arr.push_back({ i,num });
	}
	sort(arr.begin(), arr.end(), cmp);
	scanf("%lld", &n);
	while (n--) {
		scanf("%lld", &tar);
		ll l = 0, r = arr.size();
		while ((l + 1) < r) {
			ll mid = (l + r) >> 1;
			if (arr[mid].num > tar) {
				r = mid;
			}
			else {
				l = mid;
			}
		}
		if (arr[l].num == tar) {
			printf("%lld\n", arr[l].fir);
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}