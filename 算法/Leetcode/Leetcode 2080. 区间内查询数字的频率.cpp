#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class RangeFreqQuery {
public:

    map<int, vector<int>> mmp;

    RangeFreqQuery(vector<int>& arr) {
        int sz = arr.size();
        for (int i = 0; i < sz; i++) {
            mmp[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        int l = -1, r = mmp[value].size(), ll = -1, rr = mmp[value].size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mmp[value][mid] < left) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        while ((ll + 1) < rr) {
            int mid = (ll + rr) / 2;
            if (mmp[value][mid] <= right) {
                ll = mid;
            }
            else {
                rr = mid;
            }
        }
        return rr - l - 1;
    }

};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */