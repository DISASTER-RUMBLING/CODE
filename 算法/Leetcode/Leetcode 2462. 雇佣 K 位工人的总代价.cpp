#define _CRT_SECURE_NO_WARNINGS
#include<queue>
#include<vector>

using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {
    long long res = 0;
    long long sz = costs.size();
    if (candidates * 2 + k > sz) {
        sort(costs.begin(), costs.end());
        for (int i = 0; i < k; i++) {
            res += (long long)costs[i];
        }
        return res;
    }
    priority_queue<int,vector<int>,greater<int>> beg, ed;
    for (int i = 0; i < candidates; i++) {
        if (i < (sz - i - 1)) {
            beg.push(costs[i]);
            ed.push(costs[sz - 1 - i]);
        }
        else {
            beg.push(costs[i]);
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < k; i++) {
        if (beg.top() <= ed.top()) {
            res += (long long)beg.top();
            beg.pop();
            if ((l + candidates) < (sz - candidates - r)) {
                beg.push(costs[l + candidates]);
            }
            l++;
        }
        else {
            res += (long long)ed.top();
            ed.pop();
            if ((l + candidates) < (sz - candidates - r)) {
                ed.push(costs[sz - r - candidates - 1]);
            }
            r++;
        }
    }
    return res;
}