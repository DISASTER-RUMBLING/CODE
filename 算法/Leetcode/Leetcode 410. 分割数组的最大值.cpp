#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool Check(vector<int>& arr, int k, int mid) {
        int l = 0, sz = arr.size(), num = 0;
        for (int i = 0; i < sz; i++) {
            if (arr[i] - arr[l] > mid) {
                l = i - 1;
                num++;
                if (num > k) {
                    return false;
                }
            }
        }
        return num + 1 > k ? false : true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sz = nums.size(), l = 0;
        vector<int> arr(sz + 1, 0);
        for (int i = 1; i <= sz; i++) {
            arr[i] = arr[i - 1] + nums[i - 1];
            l = max(l, nums[i - 1]);
        }
        l--;
        int r = arr[sz] + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (Check(arr, k, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }

};