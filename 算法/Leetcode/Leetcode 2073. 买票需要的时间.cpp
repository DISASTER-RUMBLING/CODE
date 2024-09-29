#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tar = tickets[k], res = 0, sz = tickets.size();
        for (int i = 0; i < sz; i++) {
            if (i <= k) {
                res += min(tar, tickets[i]);
            }
            else {
                res += min(tar - 1, tickets[i]);
            }
        }
        return res;
    }
};