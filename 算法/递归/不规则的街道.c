//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//
//#define S(a) (a)*(a)
//
//void degree(int grade, long long No, long long* xx, long long* yy) {
//	if (grade == 1) {
//		if (No == 1) {
//			*xx = 0, * yy = 0;
//		}
//		else if (No == 2) {
//			*xx = 0, * yy = 1;
//		}
//		else if (No == 3) {
//			*xx = 1, * yy = 1;
//		}
//		else {
//			*xx = 1, * yy = 0;
//		}
//		return;
//	}
//	else {
//		long long L = pow(2, grade - 1);
//		long long sqare = S(L);
//		if (grade != 1) {
//			if (No <= sqare) {
//				degree(grade - 1, No, xx, yy);
//				long long tmp = *xx;
//				*xx = *yy;
//				*yy = tmp;
//			}
//			else if (No <= 2 * sqare) {
//				degree(grade - 1, No - sqare, xx, yy);
//				*yy = L + *yy;
//			}
//			else if (No <= 3 * sqare) {
//				degree(grade - 1, No - 2 * sqare, xx, yy);
//				*xx = L + *xx;
//				*yy = L + *yy;
//			}
//			else {
//				degree(grade - 1, No - 3 * sqare, xx, yy);
//				long long tmp = *xx;
//				*xx = 2 * L - *yy - 1;
//				*yy = L - tmp - 1;
//			}
//		}
//	}
//	return;
//}
//
//int main() {
//
//
//	int num;
//	scanf("%d", &num);
//	for (int i = 0; i < num; i++) {
//		int grade;
//		long long num1, num2, x1, y1, x2, y2;
//		scanf("%d %lld %lld", &grade, &num1, &num2);
//		degree(grade, num1, &x1, &y1), degree(grade, num2, &x2, &y2);
//		printf("%.0f\n", 10 * sqrt(S(x1 - x2) + S(y1 - y2)));
//	}
//
//	return 0;
//}