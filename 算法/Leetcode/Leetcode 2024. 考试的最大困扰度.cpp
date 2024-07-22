#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, r = 0, ttimes = 0, ftimes = 0, res = 1;
        while (r < answerKey.size()) {
            if (answerKey[r] == 'T') {
                ttimes += 1;
            }
            else {
                ftimes += 1;
            }
            while (ttimes > k && ftimes > k) {
                if (answerKey[l] == 'T') {
                    ttimes -= 1;
                }
                else {
                    ftimes -= 1;
                }
                l++;
            }
            r++;
            res = max(res, ttimes + ftimes);
        }
        return res;
    }
};