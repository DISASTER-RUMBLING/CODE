#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            ans += cardPoints[i];
        }
        if (k == cardPoints.size()) {
            return ans;
        }
        for (int i = 0; i < k; i++) {
            res = max(res, ans);
            ans += (cardPoints[cardPoints.size() - i - 1] - cardPoints[k - i - 1]);
        }
        res = max(res, ans);
        return res;
    }
};