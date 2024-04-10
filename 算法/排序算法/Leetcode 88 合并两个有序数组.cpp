#define _CRT_SECURE_NO_WARNINGS
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1;
        n--, m--;
        while (n != -1 || m != -1) {
            if (n == -1 || (m > -1 && nums1[m] > nums2[n])) {
                nums1[j--] = nums1[m--];
            }
            else {
                nums1[j--] = nums2[n--];
            }
        }
        return;
    }
};