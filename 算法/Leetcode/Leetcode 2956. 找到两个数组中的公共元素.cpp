#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(2, 0);
        map<int, int> mmp1, mmp2;
        for (int i = 0; i < nums1.size(); i++) {
            mmp1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (mmp1[nums2[i]] > 0) {
                res[1]++;
            }
            mmp2[nums2[i]]++;
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (mmp2[nums1[i]] > 0) {
                res[0]++;
            }
        }
        return res;
    }
};