#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

    struct node {
        int dif, pro;
    };

    static bool Cmp(node x, node y) {
        if (x.dif == y.dif) {
            return x.pro > y.pro;
        }
        return x.dif < y.dif;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sz = difficulty.size();
        vector<node> arr(sz);
        for (int i = 0; i < sz; i++) {
            arr[i] = { difficulty[i],profit[i] };
        }
        sort(worker.begin(), worker.end());
        sort(arr.begin(), arr.end(), Cmp);
        int res = 0, now = 0, mx = 0;
        for (int i = 0; i < worker.size(); i++) {
            while (now < sz && arr[now].dif <= worker[i]) {
                mx = max(mx, arr[now].pro);
                now++;
            }
            res += mx;
        }
        return res;
    }

};