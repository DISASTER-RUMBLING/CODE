#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res(k);
        stack<int> sta;
        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            while (!sta.empty() && nums[i] < sta.top() && ((sz - i - 1) + sta.size()) >= k) {
                sta.pop();
            }
            if (sta.size() < k) {
                sta.push(nums[i]);
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            res[i] = sta.top();
            sta.pop();
        }
        return res;
    }
};