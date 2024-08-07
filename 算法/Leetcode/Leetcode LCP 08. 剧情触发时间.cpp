#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int sz = increase.size();
        vector<vector<int>> now(sz + 1, { 0,0,0 });
        for (int i = 1; i <= sz; i++) {
            for (int j = 0; j < 3; j++) {
                now[i][j] = now[i - 1][j] + increase[i - 1][j];
            }
        }
        sz = requirements.size();
        vector<int> res(sz, -1);
        for (int i = 0; i < sz; i++) {
            int l = -1, r = now.size();
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if ((now[mid][0] < requirements[i][0]) || (now[mid][1] < requirements[i][1]) || (now[mid][2] < requirements[i][2])) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            if (r != now.size()) {
                res[i] = r;
            }
        }
        return res;
    }


};