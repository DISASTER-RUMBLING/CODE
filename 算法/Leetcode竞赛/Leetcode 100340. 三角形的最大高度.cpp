#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Solution {
public:
    int check(int red, int blue, int flag) {
        int res = 0, ans = 1;
        while (red >= ans || blue >= ans) {
            if (flag) {
                if (red < ans) {
                    break;
                }
                red -= ans;
                flag = 0;
            }
            else {
                if (blue < ans) {
                    break;
                }
                blue -= ans;
                flag = 1;
            }
            ans++;
            res++;
        }
        return res;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(check(red, blue, 0), check(red, blue, 1));
    }
};