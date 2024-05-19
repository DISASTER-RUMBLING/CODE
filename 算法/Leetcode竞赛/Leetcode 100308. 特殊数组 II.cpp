#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
		int q_sz = queries.size(), sz = nums.size();
		vector<bool> res(q_sz);
		vector<int> now(sz);
		now[0] = 0;
		for (int i = 0; i < sz - 1; i++) {
			now[i + 1] = ((nums[i] % 2) + (nums[i + 1] % 2)) == 1 ? 0 : 1;
			now[i + 1] += now[i];
		}
		for (int i = 0; i < q_sz; i++) {
			if ((queries[i][0] == queries[i][1])) {
				res[i] = true;
				continue;
			}
			else if ((queries[i][0] == (queries[i][1] - 1))) {
				res[i] = ((nums[queries[i][0]] % 2) + (nums[queries[i][1]] % 2)) == 1;
				continue;
			}
			if ((now[queries[i][1]] - now[queries[i][0]]) == 0) {
				res[i] = true;
			}
			else {
				res[i] = false;
			}
		}
		return res;
	}
};