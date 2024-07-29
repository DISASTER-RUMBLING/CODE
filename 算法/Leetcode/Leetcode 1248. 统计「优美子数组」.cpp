#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, sz = nums.size(), i = 1;
        vector<int> arr;
        arr.push_back(-1);
        for (int r = 0; r <= sz; r++) {
            if (r == sz || (nums[r] % 2) == 1) {
                arr.push_back(r);
            }
            int now = arr.size();
            if (now > (k + i)) {
                res += ((r - arr[now - 2]) * (arr[i] - arr[i - 1]));
                i++;
            }
        }
        return res;
    }

};