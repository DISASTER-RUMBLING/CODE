#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& start, int d, long long mid) {
        long long sz = start.size(), now = start[0];
        for (int i = 1; i < sz; i++) {
            if (now + mid > start[i] + d) {
                return false;
            }
            else {
                now = max((long long)now + mid, (long long)start[i]);
            }
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        long long l = 0, r = *start.rbegin() + 1 + d;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(start, d, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};