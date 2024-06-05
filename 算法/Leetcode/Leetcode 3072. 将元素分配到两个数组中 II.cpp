#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    int Find(vector<int>& arr, int val) {
        int l = -1, r = arr.size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] > val) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (r == arr.size()) {
            return 0;
        }
        return arr.size() - r;
    }

    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, arr11, arr22;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        arr11.push_back(nums[0]);
        arr22.push_back(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int x = Find(arr11, nums[i]), y = Find(arr22, nums[i]);
            if (x > y) {
                arr11.insert(arr11.begin() + arr11.size() - x, nums[i]);
                arr1.push_back(nums[i]);
            }
            else if (x < y) {
                arr22.insert(arr22.begin() + arr22.size() - y, nums[i]);
                arr2.push_back(nums[i]);
            }
            else {
                if (arr1.size() <= arr2.size()) {
                    arr11.insert(arr11.begin() + arr11.size() - x, nums[i]);
                    arr1.push_back(nums[i]);
                }
                else {
                    arr22.insert(arr22.begin() + arr22.size() - y, nums[i]);
                    arr2.push_back(nums[i]);
                }
            }
        }
        for (int i = 0; i < (arr2.size()); i++) {
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};