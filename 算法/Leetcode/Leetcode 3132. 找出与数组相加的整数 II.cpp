#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sz1 = nums1.size(), sz2 = nums2.size();
        for (int i = 2; i > 0; i--) {
            int now = nums2[0] - nums1[i], j = 0;
            for (int k = i; k < sz1; k++) {
                if (nums2[j] == now + nums1[k] && (++j) == sz2) {
                    return now;
                }
            }
        }
        return nums2[0] - nums1[0];
    }
};