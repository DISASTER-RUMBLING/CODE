#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>

using namespace std;

class Solution {
public:

    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> res;
        int ssz = small.size(), bsz = big.size(), l = 0, resr = bsz, resl = 0;
        if (bsz < ssz) {
            return res;
        }
        else if (bsz == ssz) {
            int flag = 1;
            for (int i = 0; i < bsz; i++) {
                if (big[i] != small[i]) {
                    flag = 0;
                    break;
                }
                if (flag) {
                    res.push_back(0);
                    res.push_back(bsz - 1);
                }
                return res;
            }
        }
        map<int, int> tar;
        for (int i = 0; i < ssz; i++) {
            tar[small[i]] += 1;
        }
        for (int r = 0; r < bsz; r++) {
            tar[big[r]] -= 1;
            int flag = 1;
            for (auto x : tar) {
                if (x.second > 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                while (tar[big[l]] + 1 <= 0) {
                    tar[big[l++]] += 1;
                }
                if ((resr - resl) > (r - l)) {
                    resr = r;
                    resl = l;
                }
            }
        }
        int flag = 1;
        for (int i = 0; i < ssz; i++) {
            if (tar[small[i]] > 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            res.push_back(resl);
            res.push_back(resr);
        }
        return res;
    }

};