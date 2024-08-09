#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool check(vector<int>& houses, vector<int>& heaters, int mid) {
        int now = heaters[0] - mid, sz1 = houses.size(), nums = 0, sz2 = heaters.size();
        for (int i = 0; i < sz1; i++) {
            if (houses[i] >= (heaters[nums] - mid) && houses[i] <= (heaters[nums] + mid)) {
                continue;
            }
            else if (houses[i] < (heaters[nums] - mid)) {
                return false;
            }
            else if (houses[i] > (heaters[nums] + mid)) {
                while (nums<sz2 && houses[i]>(heaters[nums] + mid)) {
                    nums++;
                }
                if (nums == sz2) {
                    return false;
                }
                i--;
            }
        }
        return true;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = -1, r = max(houses[houses.size() - 1], heaters[heaters.size() - 1]);
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(houses, heaters, mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return r;
    }

};