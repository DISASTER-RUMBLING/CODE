#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> res(2);
        int flag = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (abs(j - i) >= indexDifference && abs(nums[j] - nums[i]) >= valueDifference) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        res[0] = res[1] = -1;
        return res;
    }
};