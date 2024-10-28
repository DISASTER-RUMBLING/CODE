#define _CRT_SECURE_NO_WARNINGS
#include<vector>

using namespace std;

class Solution {
public:

    bool Check(vector<vector<int>>& matrix, int k, int mid) {
        int res = 0, sz = matrix.size();
        for (int i = 0; i < sz; i++) {
            res += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
        }
        return res < k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int sz = matrix.size();
        int l = matrix[0][0], r = matrix[sz - 1][sz - 1] + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (Check(matrix, k, mid)) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }

};