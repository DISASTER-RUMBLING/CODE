#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int szq = queries.size(), szw = words.size();
        vector<int> res(szq), wd(szw, 0);
        for (int i = 0; i < szw; i++) {
            char p = words[i][0];
            int times = 1;
            for (int j = 1; j < words[i].size(); j++) {
                if (p == words[i][j]) {
                    times++;
                }
                else if (p > words[i][j]) {
                    p = words[i][j];
                    times = 1;
                }
            }
            wd[i] = times;
        }
        sort(wd.begin(), wd.end());
        for (int i = 0; i < szq; i++) {
            char p = queries[i][0];
            int times = 1;
            for (int j = 1; j < queries[i].size(); j++) {
                if (p == queries[i][j]) {
                    times++;
                }
                else if (p > queries[i][j]) {
                    p = queries[i][j];
                    times = 1;
                }
            }
            int l = -1, r = szw;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (times < wd[mid]) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }
            res[i] = szw - r;
        }
        return res;
    }


};