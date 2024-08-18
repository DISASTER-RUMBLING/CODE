#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int l = 0, r = 0, zero = 0, one = 0, sz = s.size(), res = 0;
        while (r < sz) {
            if (s[r] == '0') {
                zero++;
            }
            else {
                one++;
            }
            while (l <= r && (zero > k && one > k)) {
                if (s[l] == '0') {
                    zero--;
                }
                else {
                    one--;
                }
                l++;
            }
            res += (r - l + 1);
            r++;
        }
        return res;
    }
};