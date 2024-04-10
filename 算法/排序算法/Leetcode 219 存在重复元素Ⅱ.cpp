#define _CRT_SECURE_NO_WARNINGS
#include<vector>;
#include<algorithm>;
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int a = nums.size();
        vector<int> n(a);
        for (int i = 0; i < a; i++) {
            n[i] = i;
        }
        sort(n.begin(), n.end(), [&](int i, int j) -> bool {
            if (nums[i] != nums[j]) {
                return nums[i] < nums[j];
            }
        return i < j;
            });
        for (int i = 0; i < a - 1; i++) {
            if (nums[n[i]] == nums[n[i + 1]] && abs(n[i] - n[i + 1]) <= k) {
                return true;
            }
        }
        return false;
    }
};