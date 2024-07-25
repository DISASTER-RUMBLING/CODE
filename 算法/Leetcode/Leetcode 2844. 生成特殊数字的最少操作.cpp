#define _CRT_SECURE_NO_WARNINGS
#include<string>

using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int num0 = -1, num5 = -1, sz0 = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            if (num[i] == '5' && num5 == -1) {
                num5 = i;
            }
            else if (num[i] == '0' && num0 == -1) {
                num0 = i;
            }
            if (num[i] == '0') {
                sz0++;
            }
            if (((num[i] == '0' || num[i] == '5') && num0 != -1 && num0 != i) || ((num[i] == '7' || num[i] == '2') && num5 != -1)) {
                return num.size() - (i + 2);
            }
        }
        return num.size() - sz0;
    }
};