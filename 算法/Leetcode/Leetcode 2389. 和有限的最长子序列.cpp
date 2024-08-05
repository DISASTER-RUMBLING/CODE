#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int szn = nums.size(), szq = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> res(szq);
        for (int i = 1; i < szn; i++) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < szq; i++) {
            int l = -1, r = szn;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (nums[mid] > queries[i]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            res[i] = r;
        }
        return res;
    }
};