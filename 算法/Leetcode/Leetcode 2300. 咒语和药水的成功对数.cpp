#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int sz = spells.size(), szp = potions.size();
        vector<int> res(sz);
        for (int i = 0; i < sz; i++) {
            int l = -1, r = szp;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (((long long)potions[mid] * (long long)spells[i]) < (success)) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            res[i] = (szp - r);
        }
        return res;
    }
};