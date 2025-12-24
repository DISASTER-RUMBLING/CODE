#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> sta;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < 2 * nums.size(); i++) {
            while (!sta.empty() && nums[i % nums.size()] > nums[sta.top() % nums.size()]) {
                res[sta.top() % nums.size()] = nums[i % nums.size()];
                sta.pop();
            }
            sta.push(i);
        }
        return res;
    }
};