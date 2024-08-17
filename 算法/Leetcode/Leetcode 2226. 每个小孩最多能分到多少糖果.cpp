#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    bool Check(vector<int>& candies, long long k, long long mid) {
        long long now = 0, sz = candies.size();
        for (long long i = 0; i < sz; i++) {
            now += (candies[i] / mid);
        }
        return now >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0, sz = candies.size(), r = 1e9, l = 0;
        for (long long i = 0; i < sz; i++) {
            sum += candies[i];
            r = max(r, (long long)candies[i]);
        }
        if (sum < k) {
            return 0;
        }
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(candies, k, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};