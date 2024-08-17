#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = -1, r = citations.size();
        if (citations.size() == 1) {
            return citations[0] >= 1 ? 1 : 0;
        }
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (citations[mid] >= (citations.size() - mid)) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return citations.size() - r;
    }
};