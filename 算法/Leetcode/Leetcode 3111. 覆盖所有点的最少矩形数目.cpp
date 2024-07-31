#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        map<int, int> mmp;
        for (int i = 0; i < points.size(); i++) {
            mmp[points[i][0]] += 1;
        }
        if (w == 0) {
            return mmp.size();
        }
        else {
            int res = 0, now = 0;
            for (auto x : mmp) {
                if (now <= x.first) {
                    now = x.first + w + 1;
                    res++;
                }
            }
            return res;
        }
    }
};