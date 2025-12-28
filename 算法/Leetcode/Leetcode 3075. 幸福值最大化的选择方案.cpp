#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        int sz = happiness.size();
        sort(happiness.begin(), happiness.end());
        for (int i = 0; i < k; i++) {
            res += max(happiness[sz - 1 - i] - i, 0);
            if (happiness[sz - i - 1] <= 0) break;
        }
        return res;
    }
};