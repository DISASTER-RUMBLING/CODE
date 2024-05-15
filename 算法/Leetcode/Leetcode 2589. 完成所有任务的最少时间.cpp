#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:

	static bool Cmp(vector<int>& x, vector<int> y) {
		return  x[1] < y[1];
	}

	int findMinimumTime(vector<vector<int>>& tasks) {
		sort(tasks.begin(), tasks.end(), Cmp);
		map<int, int> mmp;
		int res = 0;
		for (int i = 0; i < tasks.size(); i++) {
			for (int j = tasks[i][1]; j >= tasks[i][0]; j--) {
				if (mmp[j] == 1) {
					tasks[i][2]--;
				}
				if (tasks[i][2] <= 0) {
					break;
				}
			}
			if (tasks[i][2] <= 0) {
				continue;
			}
			for (int j = tasks[i][1]; j >= tasks[i][0]; j--) {
				if (mmp[j] != 1) {
					mmp[j] = 1;
					tasks[i][2]--;
					res++;
					if (tasks[i][2] <= 0) {
						break;
					}
				}
			}
		}
		return res;
	}

};