#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long res = 0, sz = nums.size(), num = 0;
        priority_queue<long long> st;
        for (int i = 0; i < sz; i++) {
            if (nums[i] < 0) {
                st.push(-nums[i]);
            }
            else if (nums[i]) {
                if (0 == res) {
                    res = nums[i];
                }
                else {
                    res *= nums[i];
                }
            }
            else {
                num++;
            }
        }
        while (st.size() >= 2) {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            if (res) {
                res *= (long long)(num1 * num2);
            }
            else {
                res = (long long)(num1 * num2);
            }
        }
        if (res == 0) {
            if (num) {
                return 0;
            }
            else if (!st.empty()) {
                return -st.top();
            }
        }
        return res;
    }
};