#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// 1.D
// 2.D
// 3.C
// 4.A
// 5.BD

//#include <iostream>
//using namespace std;
//
//int main() {
//
//    int n, res = 0;
//    cin >> n;
//    for (int i = 0; i <= n; i++) {
//        if (i < 10 && (i * i) % 10 == i) {
//            res++;
//        }
//        else if (i >= 10 && i < 100 && (i * i) % 100 == i) {
//            res++;
//        }
//        else if (i >= 100 && i < 1000 && (i * i) % 1000 == i) {
//            res++;
//        }
//        else if (i >= 1000 && i < 10000 && (i * i) % 10000 == i) {
//            res++;
//        }
//    }
//    cout << res;
//
//    return 0;
//}
//
//#include <cmath>
//#include <iostream>
//#include <map>
//using namespace std;
//
//int main() {
//    int n, res = 0;
//    cin >> n;
//    for (int i = 2; i <= n; i++) {
//        int flag = 1;
//        for (int j = 2; j <= (int)sqrt(i); j++) {
//            if (i % j == 0) {
//                flag = 0;
//                break;
//            }
//        }
//        if (flag) {
//            res++;
//        }
//    }
//    cout << res;
//
//    return 0;
//}