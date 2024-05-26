#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<cmath>
#include<map>

using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0;
        map<int, int> mmp;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % k != 0) {
                continue;
            }
            for (int j = 1; j <= sqrt(nums1[i]); j++) {
                if (nums1[i] % j == 0) {
                    mmp[j]++;
                    if (j != nums1[i] / j) {
                        mmp[nums1[i] / j]++;
                    }
                }
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            res += mmp[k * nums2[i]];
        }
        return res;
    }
};