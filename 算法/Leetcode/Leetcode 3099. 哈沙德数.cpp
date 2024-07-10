#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int ans = 0, a = x;
        while (a > 0) {
            ans += a % 10;
            a /= 10;
        }
        return x % ans == 0 ? ans : -1;
    }
};