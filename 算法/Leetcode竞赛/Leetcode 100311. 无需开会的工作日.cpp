#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct dat
{
    int beg, ed;
};

bool Cmp(dat x, dat y) {
    if (x.beg != y.beg) {
        return x.beg < y.beg;
    }
    return x.ed < y.ed;
}

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res = days;
        vector<dat> arr;
        for (int i = 0; i < meetings.size(); i++) {
            arr.push_back({ meetings[i][0], meetings[i][1] });
        }
        sort(arr.begin(), arr.end(), Cmp);

        int l = arr[0].beg, r = arr[0].ed;
        res -= (r - l) + 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i].beg >= r) {
                if (arr[i].beg == r) {
                    res++;
                }
                l = arr[i].beg;
                r = arr[i].ed;
                res -= (r - l) + 1;
            }
            else {
                if (arr[i].ed > r) {
                    res -= (arr[i].ed - r);
                    r = arr[i].ed;
                }
                if (arr[i].beg < l) {
                    res -= (l - arr[i].beg);
                    res = arr[i].beg;
                }
            }
        }
        return res;
    }
};