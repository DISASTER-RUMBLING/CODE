#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        map<int, int> mmp;
        for (int i = 0; i < nums.size(); i++) {
            mmp[nums[i]]++;
        }
        for (auto x : mmp) {
            if (x.second == 2) {
                res = res == 0 ? x.first : res ^ x.first;
            }
        }
        return res;
    }
};