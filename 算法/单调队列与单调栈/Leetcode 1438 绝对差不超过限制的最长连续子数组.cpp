#define _CRT_SECURE_NO_WARNINGS
#include<deque>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1, l = 0;
        deque<int> min, max;
        max.push_back(0);
        min.push_back(0);
        for (int r = 1, n = nums.size(); r < n; r++) {
            while (!max.empty() && nums[max.back()] < nums[r]) {
                max.pop_back();
            }
            while (!min.empty() && nums[min.back()] > nums[r]) {
                min.pop_back();
            }
            max.push_back(r);
            min.push_back(r);
            while ((nums[max.front()] - nums[min.front()]) > limit) {
                if (max.front() == l) {
                    max.pop_front();
                }
                if (min.front() == l) {
                    min.pop_front();
                }
                l++;
            }
            ans = ans > (r - l + 1) ? ans : (r - l + 1);
        }
        return ans;
    }
};