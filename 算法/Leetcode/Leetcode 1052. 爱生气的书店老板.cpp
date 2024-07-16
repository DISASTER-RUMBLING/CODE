#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, ans = 0, now = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (!grumpy[i]) {
                now += customers[i];
            }
        }
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) {
                ans += customers[i];
            }
        }
        for (int i = minutes; i < customers.size(); i++) {
            res = max(res, ans);
            if (grumpy[i - minutes]) {
                ans -= customers[i - minutes];
            }
            if (grumpy[i]) {
                ans += customers[i];
            }
        }
        res = max(res, ans);
        return res + now;
    }
};