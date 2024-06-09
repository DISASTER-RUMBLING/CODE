#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxTotalReward(vector<int>& rewardValues) {
		map<int, int> mmp;
		sort(rewardValues.begin(), rewardValues.end());
		for (int i = 0; i < rewardValues.size(); i++) {
			for (auto& x : mmp) {
				if (x.first >= rewardValues[i]) {
					break;
				}
				mmp[rewardValues[i] + x.first] += 1;
			}
			mmp[rewardValues[i]] += 1;
		}
		return (*mmp.rbegin()).first;
	}
};