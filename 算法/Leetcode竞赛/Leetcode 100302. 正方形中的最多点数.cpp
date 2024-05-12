#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;



class Solution {

public:

    struct node {
        int x;
        char s;
    };

    static bool Cmp(node x, node y) {
        return x.x < y.x;
    }

    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int sz = s.size();
        vector<node> arr(sz);
        for (int i = 0; i < sz; i++) {
            arr[i] = { max(abs(points[i][0]),abs(points[i][1])),s[i] };
        }
        sort(arr.begin(), arr.end(), Cmp);
        int res = 0, last = 0;
        int now = arr[0].x, site = 0;
        map<char, bool> mmp;
        while (1) {
            while (site < sz && arr[site].x <= now) {
                if (mmp[arr[site].s] == 0) {
                    mmp[arr[site].s] = 1;
                    res++;
                }
                else {
                    return last;
                }
                site++;
            }
            last = res;
            if (site == sz) {
                return last;
            }
            now++;
        }
    }

};