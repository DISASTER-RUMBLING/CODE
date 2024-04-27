#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        map<int, bool> mmp;
        for (int i = 0; i < nums1.size(); i++) {
            bool flag = 0;
            int mx = -1;
            int now = 0;
            while (now < nums2.size()) {
                if (nums2[now] == nums1[i] && !flag) {
                    flag = 1;
                }
                if (flag && nums2[now] > nums1[i]) {
                    mx = nums2[now];
                    break;
                }
                now++;
            }
            arr.push_back(mx);
        }
        return arr;
    }
};