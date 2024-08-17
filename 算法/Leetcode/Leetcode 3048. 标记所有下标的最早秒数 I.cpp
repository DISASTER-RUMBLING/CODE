#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& nums, vector<int>& changeIndices, int mid) {
        vector<pair<int, int>> use(nums.size(), { -1,-1 });
        for (int i = 0; i < mid && i < changeIndices.size(); i++) {
            //第一个int表示最晚几号考试，第二个int表示需要几天复习
            use[(changeIndices[i] - 1)] = { 1 + i,nums[changeIndices[i] - 1] };
        }
        sort(use.begin(), use.end());
        if (use[0].first == -1) {
            return false;
        }
        int last = 0, now = 0;
        for (int i = 0; i < nums.size(); i++) {
            now += (use[i].first - last - 1);
            if (now < use[i].second) {
                return false;
            }
            now -= use[i].second;
            last = use[i].first;
        }
        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int l = nums.size() - 1, r = changeIndices.size() + 1;
        if (l + 1 > r - 1) {
            return -1;
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (Check(nums, changeIndices, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return l == changeIndices.size() ? -1 : r;
    }


};