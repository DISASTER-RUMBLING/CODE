#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        if (k == 10) {
            return 1;
        }
        string nums = to_string(num);
        int now = 0, use = 0;
        for (int i = 0; i < (k); i++) {
            now = (now * 10) + (nums[i] - '0');
            use = (use == 0 ? 10 : use * 10);
        }
        int res = 0;
        for (int i = (k - 1); i < nums.size(); i++) {
            if (now != 0 && (num % now) == 0) {
                res++;
            }
            if ((i + 1) < nums.size()) {
                now = (now * 10 + (nums[i + 1] - '0')) % use;
            }
        }
        return res;
    }
};