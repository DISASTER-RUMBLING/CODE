#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int l = 0, sz = colors.size();
        vector<int> use(sz, 0);
        while (l < sz) {
            int lon = 1;
            while (colors[(l + lon) % sz] != colors[(l + lon - 1) % sz]) {
                if (lon > (sz + k - 2)) {
                    break;
                }
                if (lon >= (k - 1) && !use[(l + lon) % sz]) {
                    res++;
                    use[(l + lon) % sz] = 1;
                }
                lon++;
            }
            l += lon;
        }
        return res;
    }
};