#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        vector<int> j(2);
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(target - nums[i]) != h.end()) {
                j[0] = h[target - nums[i]];
                j[1] = i;
                break;
            }
            h[nums[i]] = i;
        }
        return j;
    }
};