#define _CRT_SECURE_NO_WARNINGS
#include<vector>;
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), p1 = 0, p2 = 0, p = 0;
        vector<int> num(n + m);
        while (p1 < n || p2 < m) {
            if (p2 == m || (p1 < n && nums1[p1] <= nums2[p2])) {
                num[p++] = nums1[p1++];
            }
            else {
                num[p++] = nums2[p2++];
            }
        }
        if (p % 2 == 0) {
            return (num[(n + m) / 2] + num[(p / 2) - 1]) / 2.0;
        }
        else {
            return num[(p / 2)];
        }
    }
};