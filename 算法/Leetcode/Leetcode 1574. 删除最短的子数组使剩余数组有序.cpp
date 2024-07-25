#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int sz = arr.size(), res = sz + 1, l = 0, r = sz - 1;
        while (r > 0 && arr[r] >= arr[r - 1]) {
            r--;
        }
        if (!r) {
            return 0;
        }
        res = r;
        while ((!l || arr[l] >= arr[l - 1])) {
            while (r<sz && arr[l]>arr[r]) {
                r++;
            }
            res = min(res, r - l - 1);
            l++;
        }
        return res;
    }
};