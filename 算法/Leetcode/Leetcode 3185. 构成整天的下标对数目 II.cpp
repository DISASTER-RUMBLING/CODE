#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long res = 0, sz = hours.size();
        vector<long long> arr(24, 0);
        for (long long i = 0; i < sz; i++) {
            arr[hours[i] % 24] += 1;
        }
        for (long long i = 1; i < 12; i++) {
            res += (long long)(arr[i] * arr[24 - i]);
        }
        res += max((long long)(arr[12] * (arr[12] - 1) / 2), (long long)0);
        res += max((long long)0, (long long)(arr[0] * (arr[0] - 1) / 2));
        return res;
    }
};