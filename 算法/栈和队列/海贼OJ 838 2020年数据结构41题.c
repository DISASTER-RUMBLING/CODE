#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

///*************************************************************************
//    > File Name: solve.cpp
//    > Author:
//    > Mail:
//    > Created Time:
// ************************************************************************/
//#include <iostream>
//#include <cstdlib>
//#include <queue>
//
//using namespace std;
//
//int min_num(int a, int b, int c) {
//    if (a > b) swap(a, b);
//    if (a > c) swap(a, c);
//    return a;
//}
//

//
//int main() {
//    int m, n, k, x;
//    queue<int> que1, que2, que3;
//    cin >> m >> n >> k;
//    for (int i = 0; i < m; i++) {
//        cin >> x;
//        que1.push(x);
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        que2.push(x);
//    }
//    for (int i = 0; i < k; i++) {
//        cin >> x;
//        que3.push(x);
//    }
//    cout << func(que1, que2, que3) << endl;
//    return 0;
//}

int func(int S1[],int S2[],int S3[]) {
    //TODO
    //定义4个数，a、b、c分别为数组S1,S2,S3当前的指向下标，flag为是否指向各数组的最后一个
    int a = 0, b = 0, c = 0, flag[3] = { 0,0,0 };
    //定义一个整形，用于存储最小的三元组
    int min_num = abs(S1[0] - S2[0]) + abs(S2[0] - S3[0]) + abs(S3[0] - S1[0]);
    //定义一个含有3各整形的数组
    int arr[3] = { S1[a],S2[b],S3[c] };
    while (1) {
        //让max指向1，最小的数字为arr[0]
        int max = 1, max_num = arr[0];
        //循环寻找最小的数字
        for (int i = 2; i < 4; i++) {
            if (max_num > arr[i - 1]) {
                max = i - 1;
                max_num = arr[i - 1];
            }
        }
        //判断是否是SX数组的最后一个数字
        if (flag[max-1] == max) {
            return min_num;
        }
        //判断哪一个是当前数组中的最小的数字，并且让其指向该数组的下一个元素
        //若为最后一个元素，则让flag为一个数字
        if (max == 1) {
            a++;
            if (a == (sizeof(S1)/sizeof(int))) {
                flag[0] = 1;
            }
        }
        else if (max == 2) {
            b++;
            if (b == (sizeof(S2) / sizeof(int))) {
                flag[1] = 2;
            }
        }
        else {
            c++;
            if (c == (sizeof(S3) / sizeof(int))) {
                flag[2] = 3;
            }
        }
        //改变三元组，并且计算、比较是否是最小的三元组
        int arr[3] = { S1[a],S2[b],S3[c] };
        int sum = (abs(arr[0] - arr[1]) + abs(arr[1] - arr[2]) + abs(arr[2] - arr[0]));
        if (min_num > sum) {
            min_num = sum;
        }
    }
}