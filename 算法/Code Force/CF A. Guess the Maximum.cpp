//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//
//using namespace std;
//
//int  main() {
//
//	int times;
//	scanf("%d", &times);
//	while (times--) {
//		int lon;
//		scanf("%d", &lon);
//		int last, now, res = 1e9;
//		for (int i = 0; i < lon; i++) {
//			scanf("%d", &now);
//			if (i > 0) {
//				res = min(res, max(now, last) - 1);
//			}
//			last = now;
//		}
//		printf("%d\n", res);
//	}
//
//	return 0;
//}