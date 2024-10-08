#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& position, int m, long long mid) {
        int last = position[0], sz = position.size();
        for (int i = 0; i < sz; i++) {
            if ((long long)(position[i] - last) >= mid) {
                last = position[i];
                m--;
            }
        }
        return m <= 1;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        long long l = 0, r = *position.rbegin() + 1;
        while (l + 1 < r) {
            long long mid = (l + r) >> 1;
            if (Check(position, m, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};