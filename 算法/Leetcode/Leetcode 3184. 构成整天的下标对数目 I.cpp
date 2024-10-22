#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int res = 0, sz = hours.size();
        vector<int> arr(24, 0);
        for (int i = 0; i < sz; i++) {
            arr[hours[i] % 24] += 1;
        }
        for (int i = 1; i < 12; i++) {
            res += arr[i] * arr[24 - i];
        }
        res += max(arr[12] * (arr[12] - 1) / 2, 0);
        res += max(0, arr[0] * (arr[0] - 1) / 2);
        return res;
    }
};