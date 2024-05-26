#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> res(queries.size()), pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                pos.push_back(i);
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] > pos.size()) {
                res[i] = -1;
                continue;
            }
            res[i] = pos[queries[i] - 1];
        }
        return res;
    }
};