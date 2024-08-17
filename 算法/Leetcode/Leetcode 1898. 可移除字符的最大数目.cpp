#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:


    bool Check(string s, string p, vector<int> removable, int mid) {
        sort(removable.begin(), removable.begin() + mid);
        int nows = 0, nowp = 0, szs = s.size(), szp = p.size(), nowr = 0;
        while (nows < szs && nowp < szp) {
            if (nowr < mid && removable[nowr] == nows) {
                nows++;
                nowr++;
                continue;
            }
            if (s[nows] == p[nowp]) {
                nows++;
                nowp++;
            }
            else {
                nows++;
            }
        }
        if (nowp == szp) {
            return true;
        }
        return false;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = -1, r = 1 + removable.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (Check(s, p, removable, mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
    }


};