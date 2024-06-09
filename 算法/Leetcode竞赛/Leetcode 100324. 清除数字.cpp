#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int findWinningPlayer(vector<int>& skills, int k) {
		int ans = 0, mx = skills[0];
		for (int i = 0; i < skills.size(); i++) {
			int now = 1;
			while (ans != k) {
				if ((i + now) < skills.size() && skills[i] > skills[i + now]) {
					ans++;
					now++;
				}
				else {
					break;
				}
			}
			mx = max(mx, skills[i]);
			if (ans == k || (i + now) == skills.size()) {
				return i;
			}
			else {
				i = i + now - 1;
				ans = 1;
			}
		}
		return mx;
	}
};