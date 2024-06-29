#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            while (num >= 10) {
                num /= 10;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                if (gcd(num, nums[j] % 10) == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};