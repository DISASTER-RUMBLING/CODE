#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), p1 = 0, p2 = n - 1;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        sort(arr.begin(), arr.end(), [&](int i, int j)->bool {
            return nums[i] < nums[j];
            });
        while ((nums[arr[p1]] + nums[arr[p2]]) != target) {
            if ((nums[arr[p1]] + nums[arr[p2]]) > target) {
                p2--;
            }
            else {
                p1++;
            }
        }
        vector<int> a(2);
        a[0] = arr[p1], a[1] = arr[p2];
        return a;
    }
};