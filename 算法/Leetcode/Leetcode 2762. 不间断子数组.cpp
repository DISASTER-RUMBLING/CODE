#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<set>

using namespace std;

class Solution {
public:

    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int l = 0, sz = nums.size();
        multiset<int> arr;
        for (int r = 0; r < sz; r++) {
            arr.insert(nums[r]);
            while ((*arr.rbegin() - *arr.begin()) > 2) {
                arr.erase(arr.find(nums[l]));
                l++;
            }
            res += (r - l + 1);
        }
        return res;
    }

};