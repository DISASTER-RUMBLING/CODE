#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        int ans = 0;
        while (mainTank >= 5 && additionalTank > 0) {
            if (mainTank >= 5) {
                res += 50;
                mainTank -= 4;
                additionalTank--;
            }
        }
        res += mainTank * 10;
        return res;
    }
};