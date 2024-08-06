#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, mod = 1e9 + 7, mx = 0, sz = nums1.size();
        vector<int> arr = nums1;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < sz; i++) {
            int l = -1, r = sz, now = abs(nums1[i] - nums2[i]);
            if (0 == now) {
                continue;
            }
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (arr[mid] <= nums2[i]) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            int flag = -1;
            if (l == -1) {
                flag = 1;
            }
            else if (r == sz) {
                flag = 0;
            }
            else {
                if (abs(nums2[i] - arr[l]) > abs(arr[r] - nums2[i])) {
                    flag = 1;
                }
                else {
                    flag = 0;
                }
            }
            if (1 == flag && (now - abs(nums2[i] - arr[r])) > mx) {
                res = (res + mx + abs(nums2[i] - arr[r])) % mod;
                mx = (now - abs(nums2[i] - arr[r]));
            }
            else if (0 == flag && (now - abs(nums2[i] - arr[l])) > mx) {
                res = (res + mx + abs(nums2[i] - arr[l])) % mod;
                mx = (now - abs(nums2[i] - arr[l]));
            }
            else {
                res = (res + now) % mod;
            }
        }
        return res;
    }
};