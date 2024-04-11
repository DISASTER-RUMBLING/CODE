//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<vector>
//
//using namespace std;
//
//#define ll long long
//
////arr[0]用于储存有多少普通金属，arr[1]用于储存最终得到多少个特殊金属
//vector<ll> arr[2];
//ll n, sz;
//
//bool TARMAX(ll now) {
//	for (int i = 0; i < sz; i++) {
//		if (arr[0][i] / now < arr[1][i]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//bool TARMIN(ll now) {
//	for (int i = 0; i < sz; i++) {
//		if ((arr[0][i] / now) > arr[1][i]) {
//			return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//
//	scanf("%lld", &n);
//	ll mx = 0;
//	while (n--) {
//		ll num, res;
//		scanf("%lld%lld", &num, &res);
//		mx = max(mx, num);
//		arr[0].push_back(num);
//		arr[1].push_back(res);
//	}
//	sz = arr[0].size();
//	ll l = 0, r = mx;
//	while (l + 1 < r) {
//		ll mid = (l + r) >> 1;
//		if (TARMIN(mid)) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	printf("%d ", r);
//	l = 0, r = mx;
//	while (l + 1 < r) {
//		ll mid = (l + r) >> 1;
//		if (TARMAX(mid)) {
//			l = mid;
//		}
//		else {
//			r = mid;
//		}
//	}
//	printf("%d", l);
//
//	return 0;
//}