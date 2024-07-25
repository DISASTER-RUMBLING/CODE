#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0, l = 0, sz = nums.size(), num = 0;
        map<int, int> mmp, use;
        for (int i = 0; i < sz; i++) {
            mmp[nums[i]] += 1;
        }
        for (int r = 0; r < sz; r++) {
            if (!use[nums[r]]) {
                num += 1;
            }
            use[nums[r]] += 1;
            while (num == mmp.size()) {
                res += (sz - r);
                use[nums[l]] -= 1;
                if (!use[nums[l]]) {
                    num--;
                }
                l++;
            }
        }
        return res;
    }

};