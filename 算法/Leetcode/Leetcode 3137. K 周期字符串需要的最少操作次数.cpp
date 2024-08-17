#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string, int> mmp;
        int sz = word.size(), res = 0;
        for (int i = 0; i < sz; i += k) {
            string now = word.substr(i, k);
            mmp[now] += 1;
            res = max(mmp[now], res);
        }
        return (sz / k) - res;
    }
};