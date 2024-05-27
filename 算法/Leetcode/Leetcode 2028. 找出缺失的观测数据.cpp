#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sum += rolls[i];
        }
        sum = (n + rolls.size()) * mean - (sum);
        if (sum > n * 6 || sum <= 0 || sum < n) {
            return {};
        }
        vector<int> res(n);
        int a = sum % n;
        for (int i = 0; i < n; i++) {
            res[i] = sum / n + (a-- > 0 ? 1 : 0);
        }
        return res;
    }
};